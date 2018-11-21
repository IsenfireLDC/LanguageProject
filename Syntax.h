/*
 * Syntax.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Ben Klemp - temp
 */

#ifndef SYNTAX_H_
#define SYNTAX_H_

#include "TokenType.h"


namespace std {

struct binop {
	Token op;
	Token out;
	Token in[2];
};

struct unop {
	Token op;
	Token out;
	Token in;
};

struct assign {
	Token op;
	Token type;
	Token in; //name
	Token out; //value  //TODO: See if this will work; add different type?
};

class Syntax {
public:
	Syntax();
};

}


#endif /* SYNTAX_H_ */
