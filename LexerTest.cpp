/*
 * LexerTest.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: Ben Klemp
 */

#include "Lexer.h"
#include "Printing.h"

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>

#include "TokenType.h"

using namespace std;
using namespace compiler;

int main2() {
	cout << "Running..." << endl;
	fstream file;
	file.open("test.mklng", ios::in);

	stringstream buffer;
	buffer << file.rdbuf();

	string input = buffer.str();
	file >> input;

	Lexer lexer = Lexer(input);
	cout << "Lexing...(verbose)" << endl;
	vector<Token> tokens = lexer.allTokens();
	cout << "Finished Lexing." << endl;
	unsigned int i = 0;
	while (i < tokens.size()) {
		cout << *(p.point + (int)tokens[i++].type) << " " << tokens[i].value << endl;
	}
	cout << "Finished." << endl;
	return 0;
}
