/*
 * TokenType.cpp
 *
 *  Created on: Nov 14, 2018
 *      Author: Ben Klemp
 */


#include "TokenType.h"

namespace compiler {

Token::Token(TokenTypes type, std::string value, int column, int line) {
	this->type = type;
	this->value = value;
	this->column = column;
	this->line = line;
}

}
