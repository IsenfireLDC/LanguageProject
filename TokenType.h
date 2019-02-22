/*
 * TokenType.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp
 */

#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

#include "Printing.h"

#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>

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
	LBrace = 23,
	RBrace = 24,
	LBracket = 25,
	RBracket = 26,
	Semicolon = 4,
	EOI = 3,
	EOL = 0,
	UnexpectedEnd = -2,
	Null = -1
};

class Token {
public:
	Token(TokenTypes, string, int, int);
	Token();

	TokenTypes type;
	string value;
	int column;
	int line;
/*
	void print() {
		cout << *(p.point + (int)type) << ", " << value << ", " << column << ", " << line << endl;
	}
*/

	char* toString() {
		cout << "Token::toString()" << endl;
		string type = *(p.point + (int)this->type);
		int size = type.length() + this->value.length() + sizeof(this->column) + sizeof(this->line);
		char* strout = new char[size + 11];

		stringstream s;
		s << type << ", " << this->value << ", " << this->column << ", " << this->line;
		string out = s.str();

		cout << "out.length() = " << out.length() << endl;
		for (unsigned int i = 0; i < out.length(); i++) {
			strout[i] = out[i];
		}

		cout << "Token toString: " << strout << endl;
		return strout;
	};
/*
	char* operator=(Token t) {
		return t.toString();
	};
*/
};

} /* namespace std */

#endif /* TOKENTYPE_H_ */
