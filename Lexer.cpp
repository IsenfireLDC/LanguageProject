/*
 * Lexer.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp
 */

#include "Lexer.h"

#include <cctype>
#include <cstring>
#include <string>
#include <utility>
#include <vector>

#include "FSM.h"
#include "Util.h"

using namespace std;

const int NoNextState = -1;

Lexer::Lexer(string input) {
	this->input = input;
};

Token Lexer::nextToken() {
	if (this->position >= this->input.length()) {
		return Token(TokenTypes::EOI, '\0', this->line, this->column);
	}

	char c = this->input[this->position];

	if (c == '\n') {
		this->position++;
		this->line++;
		this->column = 0;
		return Token(TokenTypes::EOL, string(1, c), this->line, this->column);
	}

	if (c == ';') {
		return this->other();
	}

	if (Util::isQuote(c)) {
		return this->quote();
	}

	if (Util::isParenthesis(c)) {
		return this->parenthesis();
	}

	if (Util::isNumber(c)) {
		return this->number();
	}

	if (Util::isOperator(c)) {
		return this->op();
	}

	if (Util::isLetter(c)) {
		return this->identifier();
	}

	if (Util::isWhitespace(c)) {
		this->position++;
		this->column++;
		return this->nextToken();
	};
	throw Token(TokenTypes::Null, string(1, c), this->line, this->column);
}

Token Lexer::parenthesis() {
	int line = this->line;
	int column = this->column;
	char c = input[this->position];

	this->position++;
	this->column++;

	if (c == '(') {
		return Token(TokenTypes::LParan, string(1, '('), line, column);
	}
	return Token(TokenTypes::RParan, string(1, ')'), line, column);
}

Token Lexer::op() {
	int line = this->line;
	int column = this->column;
	string c = string(1, input[this->position]);
	TokenTypes type;

	this->position++;
	this->column++;

	if (Util::isOperator(input[this->position])) {
		c += this->input[this->position];
		this->position++;
		this->column++;
		type = Util::checkOpPair(c);
	} else {
		type = Util::checkOp(c[0]);
	};

	return Token(type, c, line, column);
}

Token Lexer::identifier() {
	string identifier = '\0';
	int line = this->line;
	int column = this->column;

	while (this->position < this->input.length()) {
		char c = this->input[this->position];

		if (!(Util::isLetter(c) || Util::isNumber(c) || c == '_')) break;

		identifier += c;
		this->position++;
	}

	return Token(TokenTypes::Identifier, identifier, line, column);
}

Token Lexer::quote() {
	string quote = string(1, input[this->position]);
	int line = this->line;
	int column = this->column;

	this->column++;
	this->position++;

	bool backslash = false;
	char start = quote[0];

	while (this->position < this->input.length()) {
		char c = input[this->position];
		quote += c;

		this->position++;
		this->column++;

		if (Util::isQuote(c) && !backslash && c == start) return Token(TokenTypes::Quote, quote, line, column);
		if (c == '\n') {
			this->line++;
			this->column = 0;
		}
		if (c == '\\') {
			backslash = true;
		} else {
			backslash = false;
		}
	}

	throw Token(TokenTypes::UnexpectedEnd, quote, line, column);
};

Token Lexer::number() {
	int line = this->line;
	int column = this->column;
	FSM num = FSM();
	string input = this->input.substr(this->position);

	tuple<bool, string> state;
	state = num.run(input);
	string str = get<1>(state);

	if (get<0>(state)) {
		this->position+=str.length();
		this->column+=str.length();
		return Token(TokenTypes::Number, str, line, column);
	}

	return Token(TokenTypes::Null, str, line, column);
};

Token Lexer::other() {
	char c = this->input[this->position];
	int column = this->column;

	this->position++;
	this->column++;

	if (c == ';') return Token(TokenTypes::Semicolon, string(1, ';'), this->line, column);
	return Token(TokenTypes::Null, '\000', this->line, column);
}

vector<Token> Lexer::allTokens() {
	Token token = this->nextToken();
	vector<Token> tokens;

	while (token.type != TokenTypes::EOI) {
		tokens.push_back(token);
		token = this->nextToken();
	}
	tokens.push_back(token);

	return tokens;
}

int main() {
	return 0;
}
