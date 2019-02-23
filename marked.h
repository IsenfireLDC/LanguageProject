/*
 * marked.h
 *
 *  Created on: Feb 22, 2019
 *      Author: Ben Klemp - temp
 */

#ifndef MARKED_H_
#define MARKED_H_

#include "TokenType.h"


namespace compiler {

class Marked {
public:
	Marked(Token*);
	Marked(Token*, Marked*, int);
	Marked(Token*, Marked*, int, bool)

	void setContainer(Marked* container) {
		this->container = container;
	};
	void setLine(int line) {
		this->line = line;
	};
	void setKeyword(bool isKeyword) {
		this->isKeyword = isKeyword;
	};

private:
	Token* lexeme;
	Marked* container;
	int line;
	bool isKeyword = false;
};

Marked* def_container = &Marked(def_token); //TODO: Add separate container class?

}


#endif /* MARKED_H_ */
