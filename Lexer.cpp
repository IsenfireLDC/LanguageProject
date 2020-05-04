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
#include <iostream>

#include "FSM.h"
#include "Util.h"

using namespace compiler;

Lexer::Lexer(std::string input) {
	this->input = input;
};

Token* Lexer::nextToken() {
	std::cout << "Finding Token at position: " << this->position << " of " << input.length() << std::endl;
	if (this->position >= this->input.length()) { //end of input
		return new Token(TokenTypes::EOI, "", this->line, this->column);
	};

	char c = this->input[this->position];

	if (c == '\n') { //newline
		std::cout << "Newline" << std::endl;
		this->position++;
		this->line++;
		this->column = 0;
		return new Token(TokenTypes::EOL, std::string(1, c), this->line, this->column);
	};

	if (c == ';') { //semicolon
		std::cout << "Semicolon" << std::endl;
		return this->other();
	};

	if (Util::isQuote(c)) { //quotes ", '
		std::cout << "Quote" << std::endl;
		return this->quote();
	};

	if (Util::isParenthesis(c)) { //parentheses ()
		std::cout << "Parenthesis" << std::endl;
		return this->parenthesis();
	};

	if (Util::isNumber(c)) { //digit 0-9
		std::cout << "Number" << std::endl;
		return this->number();
	};

	if (Util::isOperator(c)) { //TODO: Check which ops are implemented
		std::cout << "Operator" << std::endl;
		return this->op();
	};

	if (Util::isLetter(c)) { //Alpha character [a-zA-Z]
		std::cout << "Identifier" << std::endl;
		return this->identifier();
	};

	if (Util::isWhitespace(c)) { //space, tab
		std::cout << "Whitespace" << std::endl;
		this->position++;
		this->column++;
		return this->nextToken();
	};

	//Throw an error if the token is not identifiable, maybe just push null token later
	throw "Error: Null Token\n"/*Token(TokenTypes::Null, std::string(1, c), this->line, this->column)*/;
};

Token* Lexer::parenthesis() {
	int column = this->column;
	char c = input[this->position];

	this->position++;
	this->column++;

	if (c == '(') {
		return new Token(TokenTypes::LParan, std::string(1, '('), this->line, column);
	}
	return new Token(TokenTypes::RParan, std::string(1, ')'), this->line, column);
};

Token* Lexer::op() {
	int line = this->line;
	int column = this->column;
	std::string c = std::string(1, input[this->position]);
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

	return new Token(type, c, line, column);
};

Token* Lexer::identifier() {
	std::cout << "Lexing identifier..." << std::endl;
	std::string identifier = "";
	int line = this->line;
	int column = this->column;

	while (this->position < this->input.length()) {
		char c = this->input[this->position];

		if (!(Util::isLetter(c) || Util::isNumber(c) || c == '_')) break;

		identifier += c;
		this->position++;
	}

	return new Token(TokenTypes::Identifier, identifier, line, column);
};

Token* Lexer::quote() {
	std::string quote = std::string(1, input[this->position]);
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

		if (Util::isQuote(c) && !backslash && c == start) return new Token(TokenTypes::Quote, quote, line, column);
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

	//Thrown if the input ends before the quote
	throw "Error: Unexpected End"/*Token(TokenTypes::UnexpectedEnd, quote, line, column)*/;
};

Token* Lexer::number() {
	std::cout << "Lexing number..." << std::endl;
	int column = this->column;
	FSM num = FSM();
	std::string input = this->input.substr(this->position);
	std::cout << "Starting FSM..." << std::endl;

	std::tuple<int, std::string> state;
	state = num.run(input);
	std::string str = get<1>(state);
	std::cout << "FSM finished." << std::endl;
	std::cout << "states " << get<0>(state) << " " << get<1>(state) << "." << std::endl;

	if (get<0>(state)) {
		std::cout << "Adding length..." << str.length() << std::endl;
		this->position+=str.length();
		this->column+=str.length();
		return new Token(TokenTypes::Number, str, this->line, column);
	}

	return new Token(TokenTypes::Null, str, this->line, column);
};

Token* Lexer::other() {
	char c = this->input[this->position];
	int column = this->column;

	this->position++;
	this->column++;

	if (c == ';') return new Token(TokenTypes::Semicolon, std::string(1, c), this->line, column);
	return new Token(TokenTypes::Null, std::string(1, c), this->line, column);
};

std::vector<Token*> Lexer::allTokens() {
	Token* token;
	std::vector<Token*> tokens;

	do {
		token = this->nextToken();
		tokens.push_back(token);
	} while (token->type != TokenTypes::EOI);

	return tokens;
};
