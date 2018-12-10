/*
 * Test.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Ben Klemp
 */


#include "Lexer.h"
#include "Syntax.h"
#include "Printing.h"

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>

#include "TokenType.h"

using namespace std;
using namespace compiler;

string files[] = {
		"test.mklng",
		"syntax.mklng"
};

vector<Token> lex() {
	fstream file;
	file.open(files[1], ios::in);

	stringstream buffer;
	buffer << file.rdbuf();

	string input = buffer.str();
	file >> input;

	Lexer lexer = Lexer(input);
	vector<Token> tokens = lexer.allTokens();
	unsigned int i = 0;
	while (i < tokens.size()) {
		cout << *(p.point + (int)tokens[i++].type) << " " << tokens[i].value << endl;
	}
	return tokens;
}

vector<op*> syntax(vector<Token> tokens) {
	Syntax syntax = Syntax(tokens);
	cout << "Starting Parsing..." << endl;
	vector<op*> ops = syntax.parseall();
	cout << "Finished Parsing" << endl;
	char* str = ops[0]->toString();
	cout << str << endl;
	//return ops;
	unsigned int i = 0;
	while (i < ops.size()) {
		cout << "Printing op " << i << endl;
		cout << ops[i++]->toString() << endl;
	}
	return ops;
}

int main() {
	cout << "Running..." << endl;
	cout << "Beginning Lexical Analysis..." << endl;
	vector<Token> tokens = lex();
	cout << "Lexing completed" << endl;

	cout << endl << endl << endl << endl;

	cout << "Beginning Syntax Analysis..." << endl;
	vector<op*> ops = syntax(tokens);
	cout << "Finished Syntax Analysis" << endl;
	cout << "Finished." << endl;
}
