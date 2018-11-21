/*
 * TokenType.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp
 */

#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

#include <string>

namespace std {

enum class TokenTypes {
	Identifier,
	Number,
	Add,
	Sub,
	Mul,
	Div,
	Power,
	Greater,
	GreaterOrEqual,
	Less,
	LessOrEqual,
	Equal,
	Assign,
	AddAssign,
	SubAssign,
	Incr,
	Decr,
	LParan,
	RParan,
	Quote,
	Semicolon,
	EOI,
	EOL,
	UnexpectedEnd,
	Null
};

class Token {
public:
	Token(TokenTypes, string, int, int);

	TokenTypes type;
	string value;
	int column;
	int line;
};

} /* namespace std */

#endif /* TOKENTYPE_H_ */
