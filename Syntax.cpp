/*
 * Syntax.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: Ben Klemp
 */


#include "Syntax.h"
#include "Lang.h"

#include <vector>

namespace compiler {

Syntax::Syntax(expression tokens) {
	this->tokens = tokens;
};

oper Syntax::parsenext() {
	Token current = this->tokens[this->position];
	cout << "Parsing token " << current.value;
	LangType langtype = compiler::getReservedType(current);
	cout << " of type " << (int)langtype << " at position " << this->position << endl;

	if(langtype == LangType::Unrecognized) {
		throw UnrecognizedException();
	}

	switch(langtype) {
	case LangType::Basic:
		cout << "Basic token" << endl;
		return this->parsebasic();
		break;
	default:
		cout << "Null/unimplemented token" << endl;
		this->position++;
		struct oper null;
		null.oper = current;
		return null;
	}
};

oper Syntax::parsebasic() {
	Token current = this->tokens[this->position++];

	call basic;
	basic.op.op = current;
	basic.op.type = LangType::Basic;
	while(!compiler::isEndOfStatement(current)) {
		current = this->tokens[this->position++];
		cout << "Pushing token " << this->position << endl;
		basic.params.push_back(current);
	}
	cout << "Basic token done" << endl;
	return basic;
};

vector<oper*> Syntax::parseall() {
	vector<oper*> ops;
	int i = 0;
	while (this->position < this->tokens.size()) {
		cout << "Token " << this->position << endl;
		oper next = this->parsenext();
		//if(next.op.type == TokenTypes::EOI) cout << "End of input reached" << endl; //TODO: Figure this out
		cout << "Pushing op " << i++ << endl;
		ops.push_back(&next);
	}
	return ops;
}



}
