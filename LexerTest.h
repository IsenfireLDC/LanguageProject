/*
 * LexerTest.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: Ben Klemp
 */

#include "Lexer.h"
#include "Test.h"

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>

#include "TokenType.h"

using namespace std;
using namespace compiler;

string* point = &TokenNames[2];

int lexerTest() {
	cout << "Running..." << endl;
	fstream file;
	file.open("test.mklng", ios::in);

	stringstream buffer;
	buffer << file.rdbuf();

	string input = buffer.str();
	file >> input;

	Lexer lexer = Lexer(input);
	cout << "Lexing..." << endl;
	vector<Token*> tokens = lexer.allTokens();
	cout << "Finished Lexing." << endl;
	unsigned int i = 0;
	while (i < tokens.size()) {
		cout << *(point + (int)tokens[i]->type) << " " << tokens[i]->value << endl;
		++i;
	}
	cout << "Finished." << endl;
	return 0;
}
