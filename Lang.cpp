/*
 * Lang.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: Ben Klemp - temp
 */

#include "Lang.h"
#include "Util.h"

using namespace std;
using namespace compiler;

Parser::Parser(vector<Token*> tokens) {
	this->tokens = tokens;
};

bool Parser::isKeyword(string s) {
	for(int i = 0; i < reservedTotal; i++) {
		if(s == reservedWords[i]) return true;
	};
	for(int i = 0; i < this->varnames.size(); i++) {
		if(s == this->varnames.at(i)) return true;
	};
	return false;
};

bool Parser::isValidName(string s) { //TODO: Implement name checking
	return true;
};

vector<Marked*> Parser::markAll() {
	vector<Marked*> marked;
	int tcurrent = 0;
	Token* current = this->tokens.at(0);
	Marked* scope = def_container;
	int line = 0;
	while(current->type != TokenTypes::EOI) {
		if (Util::isNewScope(current->type)) { //Check for scope change -- (, [, or {
			scope = &Marked(current, scope, line);
			marked.push_back(scope);
		} else if (current->type == TokenTypes::Identifier) {
			if(isKeyword(current->value)) {
				marked.push_back(&Marked(current, scope, line, true));
			} else {
				if (isValidName(current->value)) {
					this->varnames.push_back(current->value);
					marked.push_back(&Marked(current, scope, line, false));
				}
			}
		} else if (current->type == TokenTypes::EOL) {
			marked.push_back(&Marked(current, scope, line));
			line++;
		}

		current = this->tokens.at(++tcurrent);
	}
	return marked;
};
