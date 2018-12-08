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

Syntax::Syntax(vector<Token> tokens) {
	this->tokens = tokens;
};

op Syntax::parsenext() {
	Token* current = &this->tokens[this->position];
	cout << "Parsing token " << current->value;
	LangType langtype = compiler::getReservedType(current);
	cout << " of type " << (int)langtype << " at position " << this->position << endl;

	if(langtype == LangType::Unrecognized) {
		throw "Unrecognized";//UnrecognizedException();
	}

	switch(langtype) {
	case LangType::Basic:
		cout << "Basic token" << endl;
		return this->parsebasic();
		break;
	default:
		cout << "Null/unimplemented token" << endl;
		this->position++;
		op null = op(current);
		return null;
	}
};

op Syntax::parsebasic() {
	Token* current = &this->tokens[this->position++];

	basicop basic = basicop(current);

	while(!compiler::isEndOfStatement(current)) {
		current = &this->tokens[this->position++];
		cout << "Pushing token " << this->position << endl;
		basic.add_param(current);
	}
	cout << "Basic token done" << endl;
	return basic;
};

vector<op*> Syntax::parseall() {
	vector<op*> ops;
	int i = 0;
	while (this->position < this->tokens.size()) {
		cout << "Token " << this->position << endl;
		op next = this->parsenext();
		//if(next.op.type == TokenTypes::EOI) cout << "End of input reached" << endl; //TODO: Figure this out
		cout << "Pushing op " << i++ << endl;
		ops.push_back(&next);
	}
	return ops;
}



}
