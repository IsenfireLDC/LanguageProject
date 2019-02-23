/*
 * TokenType.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp
 */

#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

#include <string>

using namespace std;

namespace compiler {

enum class TokenTypes {
	Identifier = 1,
	Number = 2,
	Add = 5,
	Sub = 6,
	Mul = 7,
	Div = 8,
	Power = 9,
	Greater = 11,
	GreaterOrEqual = 12,
	Less = 13,
	LessOrEqual = 14,
	Equal = 10,
	Assign = 15,
	AddAssign = 16,
	SubAssign = 17,
	Incr = 18,
	Decr = 19,
	LParan = 20,
	RParan = 21,
	Quote = 22,
	Semicolon = 4,
	EOI = 3,
	EOL = 0,
	UnexpectedEnd = -2,
	Null = -1
};

class Token {
public:
	Token(TokenTypes, string, int, int);

	TokenTypes type;
	string value;
	int column;
	int line;
};

//Token* def_token = new Token(TokenTypes::Null, "", 0, 0);

} /* namespace std */

#endif /* TOKENTYPE_H_ */
