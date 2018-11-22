/*
 * Syntax.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Ben Klemp
 */

#ifndef SYNTAX_H_
#define SYNTAX_H_

#include "TokenType.h"
#include "Lang.h"

#include <vector>

namespace compiler {

typedef vector<Token> expression;
typedef vector<op> statement;
typedef int brackets[3];

struct line {
	statement s;
	brackets b;
};

class Syntax {
public:
	Syntax(expression);

	expression tokens;

	line parseline(expression);
};

}


#endif /* SYNTAX_H_ */
