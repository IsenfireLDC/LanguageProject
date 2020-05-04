/*
 * Lexer.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Ben Klemp - temp
 */

#include <string>
#include <vector>

#include "FSM.h"
#include "TokenType.h"

#ifndef LEXER_H_
#define LEXER_H_

namespace compiler {

const int NoNextState = -1;

/*class Grammar {
public:
	Grammar();
	int* states;
	int intialState;
	int* acceptingStates;
	FSM fsm;

	static int nextState(int, char) { return -1; };
};

class Number: public Grammar {
public:
	Number();
	int* states;
	int initialState;
	int* acceptingStates;
	FSM fsm/\* = FSM(this->states, Number::nextState, this->acceptingStates, this->initialState)*\/;

	static int nextState(int, char);
};*/



class Lexer {
public:
	Lexer(std::string);

	std::string input;

	Token* nextToken();

	std::vector<Token*> allTokens();

private:
	Token* identifier();
	Token* number();
	Token* op();
	Token* parenthesis();
	Token* quote();
	Token* other();

	unsigned int position = 0;
	unsigned int line = 0;
	unsigned int column = 0;
};

}

#endif /* LEXER_H_ */
