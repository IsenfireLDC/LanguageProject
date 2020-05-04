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

namespace compiler {

const int reservedTotal = 2;

static struct defaults {
	static Token* def_token = new Token(TokenTypes::Null, "", 0, 0);
	static Marked* def_container = new Marked(defaults::def_token);
	static std::string reservedWords[reservedTotal] = {
			"print",
			"read"
	};
};

class Parser {
public:
	Parser(std::vector<Token*>);

	std::vector<Marked*> markAll();

private:
	bool isKeyword(std::string);
	bool isValidName(std::string);

	std::vector<Token*> tokens;
	std::vector<std::string> varnames;
};

}


#endif /* LANG_H_ */
