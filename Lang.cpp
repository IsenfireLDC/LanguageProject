/*
 * Lang.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: Ben Klemp - temp
 */

#include "Lang.h"

#include <iostream>

#include "Util.h"

using namespace compiler;

Parser::Parser(std::vector<Token*> tokens) {
	this->tokens = tokens;
};

bool Parser::isKeyword(std::string s) {
	for(int i = 0; i < reservedTotal; i++) {
		if(s == compiler::reservedWords[i]) return true;
	};

	for(unsigned int i = 0; i < this->varnames.size(); i++) {
		if(s == this->varnames.at(i)) return true;
	};

	return false;
};

bool Parser::isValidName(std::string s) { //TODO: Implement name checking
	return true;
};

std::vector<Marked*> Parser::markAll() {
	std::vector<Marked*> marked;
	int tcurrent = 0;
	Token* current = this->tokens.at(0);
	Marked* scope = compiler::def_container;
	int line = 0;
	while(current->type != TokenTypes::EOI) {
		//cout << "next " << current->value << ", " << (int)current->type << endl;
		if (current->type == TokenTypes::LParan) {
			marked.push_back(new Marked(current, scope, line));
			scope = marked.at(tcurrent);
		} else if (current->type == TokenTypes::RParan) {
			marked.push_back(new Marked(current, scope, line));
			scope = scope->getContainer();
		} else if (current->type == TokenTypes::Identifier) {
			if(isKeyword(current->value)) {
				marked.push_back(new Marked(current, scope, line, true));
			} else {
				if (isValidName(current->value)) {
					this->varnames.push_back(current->value);
					marked.push_back(new Marked(current, scope, line, false));
				}
			}
		} else if (current->type == TokenTypes::EOL) {
			marked.push_back(new Marked(current, scope, line));
			line++;
		}

		current = this->tokens.at(++tcurrent);
	}
	return marked;
};
