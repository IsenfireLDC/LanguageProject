/*
 * Util.h
 *
 *  Created on: Nov 15, 2018
 *      Author: Ben Klemp
 */

#ifndef UTIL_H_
#define UTIL_H_

#include "TokenType.h"

namespace std {

class Util {
public:
	static bool isLetter(char ch) {
		int c = (int) ch;
		if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return true;
		return false;
	};
	static bool isNumber(char ch) {
		int c = (int) ch;
		if (c >= 48 && c <= 57) return true;
		return false;
	};
	static bool isOperator(char ch) {
		int c = (int) ch;
		if (c == 42 || c == 43 || c == 45 || c == 47 || (c >= 60 && c <= 62) || c == 94) return true;
		return false;
	};
	static TokenTypes checkOpPair(string ch) {
		if (ch[1] == '=') {
			switch(ch[0]) {
			case '=':
				return TokenTypes::Equal;
			case '<':
				return TokenTypes::LessOrEqual;
			case '>':
				return TokenTypes::GreaterOrEqual;
			case '+':
				return TokenTypes::AddAssign;
			case '-':
				return TokenTypes::SubAssign;
			}
		} else if (ch == "++") return TokenTypes::Incr;
		else if (ch == "--") return TokenTypes::Decr;
		return TokenTypes::Null;
	};
	static TokenTypes checkOp(char ch) {
		switch (ch) {
		case '+':
			return TokenTypes::Add;
		case '-':
			return TokenTypes::Sub;
		case '=':
			return TokenTypes::Assign;
		case '<':
			return TokenTypes::Less;
		case '>':
			return TokenTypes::Greater;
		case '*':
			return TokenTypes::Mul;
		case '/':
			return TokenTypes::Div;
		case '^':
			return TokenTypes::Power;
		default:
			return TokenTypes::Null;
		}
	};
	static bool isParenthesis(char ch) {
		int c = (int) ch;
		if (c == 40 || c == 41) return true;
		return false;
	};
	static bool isQuote(char ch) {
		if (ch == '\"' || ch == '\'') return true;
		return false;
	};
	static bool isWhitespace(char ch) {
		if (ch == ' ' || ch == '\t') return true;
		return false;
	};
};

}



#endif /* UTIL_H_ */
