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
#include <exception>

namespace compiler {

struct oper;
/*
struct UnrecognizedException: public exception {
	const char * what () const throw () {
		return "Unrecognized Syntax Token";
	}
} UnrecognizedException;
*/
typedef int brackets[3];

/*struct line {
	statement s;
	brackets b;
};*/

class Syntax {
public:
	Syntax(expression);

	expression tokens;
	vector<string> varnames;

	unsigned int position = 0;

	oper parsenext();

	oper parsebasic();

	vector<oper*> parseall();
};

}


#endif /* SYNTAX_H_ */
