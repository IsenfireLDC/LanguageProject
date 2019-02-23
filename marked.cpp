/*
 * marked.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: Ben Klemp - temp
 */

#include "Marked.h"

using namespace compiler;

Marked::Marked(Token* lexeme) {
	this->lexeme = lexeme;
	this->container = &0;
	this->line = -1;
};

Marked::Marked(Token* lexeme, Marked* container, int line) {
	this->lexeme = lexeme;
	this->container = container;
	this->line = line;
};

Marked::Marked(Token* lexeme, Marked* container, int line, bool isKeyword) {
	this->lexeme = lexeme;
	this->container = container;
	this->line = line;
	this->isKeyword = isKeyword;
};
