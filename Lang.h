/*
 * Lang.h
 *
 *  Created on: Feb 22, 2019
 *      Author: Ben Klemp - temp
 */

#ifndef LANG_H_
#define LANG_H_

#include <string>
#include <vector>

#include "Marked.h"
#include "TokenType.h"

using namespace std;

namespace compiler {

int reservedTotal = 2;

string reservedWords[reservedTotal] = {
		"print",
		"read"
};

class Parser {
public:
	Parser(vector<Token*>);

	bool isKeyword(string);
	bool isValidName(string);

	vector<Marked*> markAll();

private:
	vector<Token*> tokens;
	vector<string> varnames;
};

}


#endif /* LANG_H_ */
