/*
 * ParserTest.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: Ben Klemp - temp
 */

#include "Lexer.h"
#include "Test.h"

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <sstream>

#include "TokenType.h"

#include "Lang.h"
#include "Marked.h"

using namespace std;
using namespace compiler;

string* point = &TokenNames[2];

int parserTest() {
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
	cout << "Finished Lexing." << endl;

	cout << "Parsing..." << endl;
	Parser parser = Parser(tokens);
	vector<Marked*> marked = parser.markAll();

	i = 0;
	while(i < marked.size()) {
		cout << "Lexeme " << marked.at(i)->getLexeme()->value << " with scope of level " << marked.at(i)->getLevel() << " from " << marked.at(i)->getContainer()->getLine() << " at line " << marked.at(i)->getLine() << endl;
		i++;
	};
	cout << "Finished." << endl;
	return 0;
}
