/*
 * FSM.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ben Klemp
 */

#ifndef FSM_H_
#define FSM_H_

#include <string>
#include <tuple>

#include "Lexer.h"

namespace compiler {

class FSM {
public:
	FSM();

	int* states;
	int initialState;
	int* acceptingStates;
	int nextState(int, char);

	std::tuple<int, std::string> run(std::string);
	bool acceptedState(int);
};

} /* namespace std */

#endif /* FSM_H_ */
