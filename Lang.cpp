/*
 * Lang.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Ben Klemp - temp
 */

#include "Lang.h"
#include "TokenType.h"

namespace compiler {

op::op(Token op) {
	this->op = op;
};

basicop::basicop(Token op) {
	this->op = op;
};

basicop::add_param(Token param) {
	this->params.push_back(param);
};

LangToken::LangToken(Token token, LangType type/*, unsigned int position*/) {
	this->token = token;
	this->type = type;
	//this->position = position;
};

void f(Token in) {
	in.print();
};

LangType getReservedType(Token in) {
	string val = in.value;

	if(val == "print" || val == "read") return LangType::Basic;
	else if(in.type == TokenTypes::EOI) return LangType::EOI;
	//if(val == "class") return LangType::Class;
	//else if (val == "this") return LangType::Object;
	else return LangType::Unrecognized;
}

bool isEndOfStatement(Token in) {
	TokenTypes type = in.type;

	if(type == TokenTypes::EOL || type == TokenTypes::Semicolon || type == TokenTypes::EOI) return true;
	return false;
};

string reservedWords[] = { //12
		/*
		"class",	//class
		"space",	//space
		"in",		//extend
		"extends",	//extend
		"is",		//extend
		"new",		//
		"true",
		"false",
		"null",
		"this",*/
		"print",
		"read"
};

char typeChars[] = { //12
		//access
		'p',
		'h',
		//type
		'b',
		'i',
		'f',
		'd',
		's',
		'a',
		'c',
		//modifier
		'e',
		'o',
		't'
};

}
