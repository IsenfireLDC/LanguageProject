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

using namespace compiler;

int parserTest() {
	std::cout << "Running..." << std::endl;
	fstream file;
	file.open("test.mklng", ios::in);

	stringstream buffer;
	buffer << file.rdbuf();

	string input = buffer.str();
	file >> input;

	Lexer lexer = Lexer(input);
	cout << "Lexing..." << endl;
	std::vector<Token*> tokens = lexer.allTokens();
	std::cout << "Finished Lexing." << std::endl;
	unsigned int i = 0;
	while (i < tokens.size()) {
		std::cout << *(point + (int)tokens[i]->type) << " " << tokens[i]->value << std::endl;
		++i;
	}
	std::cout << "Finished Lexing." << std::endl;

	std::cout << "Parsing..." << std::endl;
	Parser parser = Parser(tokens);
	std::vector<Marked*> marked = parser.markAll();

	i = 0;
	while(i < marked.size()) {
		std::cout << "Lexeme " << marked.at(i)->getLexeme()->value << " with scope of level " << marked.at(i)->getLevel() << " from " << marked.at(i)->getContainer()->getLine() << " at line " << marked.at(i)->getLine() << std::endl;
		i++;
	};
	std::cout << "Finished." << std::endl;
	return 0;
}
