/*
 * Test.h
 *
 *  Created on: Jan 26, 2020
 *      Author: klempb
 */

#ifndef TEST_H_
#define TEST_H_


std::string TokenNames[] = {
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
};

std::string* point = &TokenNames[2];


#endif /* TEST_H_ */
