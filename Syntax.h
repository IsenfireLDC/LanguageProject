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

/*
struct UnrecognizedException: public exception {
	const char * what () const throw () {
		return "Unrecognized Syntax Token";
	}
} UnrecognizedException;
*/

class Syntax {
public:
	Syntax(vector<Token>);

	vector<Token> tokens;
	vector<string> varnames;

	unsigned int position = 0;

	op parsenext();

	op parsebasic();

	vector<op*> parseall();
};

}


#endif /* SYNTAX_H_ */
