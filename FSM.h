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

namespace std {

class FSM {
public:
	//typedef int (Grammar::*next)(int, char);
	FSM(int*, int(*)(int, char), int*, int);
	//FSM(int*, int*, int);
	virtual ~FSM();

	int* states;
	int initialState;
	int* acceptingStates;
	static int (*nextState)(int, char);
	//int nextState(int*, char);

	tuple<bool, string> run(string);
	bool acceptedState(int);
};

} /* namespace std */

#endif /* FSM_H_ */
