/*
 * Syntax.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: Ben Klemp
 */


#include "Syntax.h"

namespace compiler {

Syntax::Syntax(expression tokens) {
	this->tokens = tokens;
};

line Syntax::parseline(expression lin) {
	for (int i = 0; i < lin.size(); i++) {
		Token current = lin[i];
	}
}

}
