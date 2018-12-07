/*
 * Test.h
 *
 *  Created on: Nov 28, 2018
 *      Author: Ben Klemp - temp
 */

#ifndef TEST_H_
#define TEST_H_

//#include "Lang.h"

#include <string>


namespace compiler {

class Printing{
public:
	Printing() {};

	std::string TokenNames[30] = {
			"UnexpectedEnd",
			"Null",
			"EOL",
			"Identifier",
			"Number",
			"EOI",
			"Semicolon",
			"Add",
			"Sub",
			"Mul",
			"Div",
			"Power",
			"Equal",
			"Greater",
			"GreaterOrEqual",
			"Less",
			"LessOrEqual",
			"Assign",
			"AddAssign",
			"SubAssign",
			"Incr",
			"Decr",
			"LParan",
			"RParan",
			"Quote",
			"LBrace",
			"RBrace",
			"LBracket",
			"RBracket"
	};

	std::string* point = &TokenNames[2];

	/*
	static void printOper(op* opin) {
		LangType type = opin->type;
		switch(type) {
		case LangType::Basic:
			std::cout << opin->op.toString() << std::endl;
			break;
		default:
			std::cout << "None" << std::endl;
		}
	};
*/

};

extern Printing p;

}


#endif /* TEST_H_ */
