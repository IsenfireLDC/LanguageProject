/*
 * FSM.cpp
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp - temp
 */

#include "FSM.h"
#include "Lexer.h"

#include <string>
#include <algorithm>
#include <tuple>

namespace std {

FSM::FSM(int* states, int (Grammar::*nextState)(int, char), int* acceptingStates, int initialState) {
	this->states = states;
	this->nextState = nextState;
	this->acceptingStates = acceptingStates;
	this->initialState = initialState;
}

FSM::~FSM() {
//	delete[] this->states;
//	delete this->nextState;
//	delete[] this->acceptingStates;
//	delete this->initialState;
}

tuple<bool, string> FSM::run(string input) {
	int currentState = this->initialState;
	unsigned int i = 0;
	for (i = 0; i < input.length(); i++) {
		char c = input.at(i);
		int state = (*this->*nextState)(currentState, c);

		if (acceptedState(state)) return tuple<bool, string> (true, input.substr(0, i));

		if (state == NoNextState) {
			break;
		}
		currentState = state;
	}
	return tuple<bool, string> (false, '\000');
}

bool FSM::acceptedState(int nextState) {
	int i = 0;
	while(i < *(this->acceptingStates - 1)) {
		if (*(this->acceptingStates + i++) == nextState) return true;
	}
	return false;
}



} /* namespace std */
