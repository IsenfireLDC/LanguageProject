/*
 * FSM.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp - temp
 */

#include "FSM.h"
#include "Lexer.h"
#include "Util.h"

#include <string>
#include <algorithm>
#include <tuple>
#include <iostream>

namespace compiler {

static int states[] = {7, 1, 2, 3, 4, 5, 6, 7};
static int acceptingStates[] = {3, 2, 4, 7};

FSM::FSM() {
	this->states = &compiler::states[1];
	this->acceptingStates = &compiler::acceptingStates[1];
	this->initialState = 1;
};

int FSM::nextState(int currentState, char nextChar) {
	std::cout << "Finding next state after " << currentState << " with " << nextChar << std::endl;
	switch (currentState) {
	case 1:
		if (Util::isNumber(nextChar)) return 2;
		break;
	case 2:
		if (Util::isNumber(nextChar)) return 2;
		if (nextChar == '.') return 3;
		if (tolower(nextChar) == 'e') return 5;
		break;
	case 3:
		if (Util::isNumber(nextChar)) return 4;
		break;
	case 4:
		if (Util::isNumber(nextChar)) return 4;
		if (tolower(nextChar) == 'e') return 5;
		break;
	case 5:
		if (nextChar == '-' || nextChar == '+') return 6;
		if (Util::isNumber(nextChar)) return 7;
		break;
	case 6:
		if (Util::isNumber(nextChar)) return 7;
		break;
	case 7:
		if (Util::isNumber(nextChar)) return 7;
		break;
	};

	return NoNextState;
};

std::tuple<int, std::string> FSM::run(std::string input) {
	int currentState = this->initialState;
	unsigned int i = 0;
	std::cout << input.length() << std::endl;
	for (i = 0; i < input.length();) {
		char c = input.at(i);
		i++;
		int state = this->nextState(currentState, c);

		if (acceptedState(state)) return std::tuple<bool, std::string>(currentState, input.substr(0, i));

		if (state == NoNextState) {
			i--;
			break;
		}
		currentState = state;
	}
	return std::tuple<int, std::string> (currentState, input.substr(0, i));
}

bool FSM::acceptedState(int nextState) {
	int i = 0;
	while(i < *(this->acceptingStates - 1)) {
		if (*(this->acceptingStates + i++) == nextState) return true;
	}
	return false;
}



} /* namespace std */
