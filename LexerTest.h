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

using namespace compiler;

int lexerTest() {
	std::cout << "Running..." << std::endl;
	std::fstream file;
	file.open("test.mklng", std::ios::in);

	std::stringstream buffer;
	buffer << file.rdbuf();

	std::string input = buffer.str();
	file >> input;

	Lexer lexer = Lexer(input);
	std::cout << "Lexing..." << std::endl;
	std::vector<Token*> tokens = lexer.allTokens();
	std::cout << "Finished Lexing." << std::endl;
	unsigned int i = 0;
	while (i < tokens.size()) {
		std::cout << *(point + (int)tokens[i]->type) << " " << tokens[i]->value << std::endl;
		++i;
	}
	std::cout << "Finished." << std::endl;
	return 0;
}
