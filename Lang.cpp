/*
 * Lang.cpp
 *
 *  Created on: Nov 28, 2018
 *      Author: Ben Klemp
 */

#include "Lang.h"
#include "TokenType.h"

#include <iostream>
#include <sstream>
#include <algorithm>

namespace compiler {

/*
 * Class op
 *
 * Base class to represent any operator token/statement
 */
op::op(Token* op_token) {
	this->op_token = *op_token;
};

op::~op() {};

Token op::get_op() {
	return this->op_token;
};

char* op::toString() {
	cout << "op::toString()" << endl;
	int size = this->op_token.value.length() + 255;
	cout << size << endl;
	cout << (int)this->op_token.type << endl;
	cout << this->op_token.line << endl;
	cout << this->op_token.column << endl;
	//cout << this->op_token.value << endl;
	char* strout = new char[size];
	cout << "strout created" << endl;
	sprintf(strout, this->format, this->type, this->op_token);
	return strout;
};

/*
 * Class basicop
 *
 * Class to represent a basic operator statement
 */
basicop::basicop(Token* op_token) : op(op_token) {
	//this->op_token = *op_token;
};

void basicop::add_param(Token* param) {
	this->params.push_back(*param);
};

vector<Token> basicop::get_params() {
	return this->params;
};

char* basicop::toString() {
	cout << "basicop::toString()" << endl;
	char* strout = op::toString();
	cout << "Size: " << sizeof(strout) << endl;
	ostringstream stream;
	stream << this->format;

	for(unsigned int i = 0; i < this->params.size(); i++) {
		cout << "Adding param: " << this->params[i].value << endl;
		stream << this->params[i].toString() << " ";
	};

	string str = stream.str();

	return strout;
}



LangToken::LangToken(Token token, LangType type/*, unsigned int position*/) {
	this->token = token;
	this->type = type;
	//this->position = position;
};

void f(Token* in) {
	cout << in->toString() << endl;
};

LangType getReservedType(Token* in) {
	string val = in->value;

	if(val == "print" || val == "read") return LangType::Basic;
	else if(in->type == TokenTypes::EOI) return LangType::EOI;
	//if(val == "class") return LangType::Class;
	//else if (val == "this") return LangType::Object;
	else return LangType::Unrecognized;
}

bool isEndOfStatement(Token* in) {
	TokenTypes type = in->type;

	if(type == TokenTypes::EOL || type == TokenTypes::Semicolon || type == TokenTypes::EOI) return true;
	return false;
};

string reservedWords[] = { //12, 2
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
