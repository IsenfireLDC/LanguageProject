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
	Marked(Token*);
	Marked(Token*, Marked*, int);

private:
	Token* lexeme;
	Marked* container;
	int line;

public:
	void setContainer(Marked* container) {
		this->container = container;
	};
	void setLine(int line) {
		this->line = line;
	};
};

Marked* def_container = &Marked(def_token);

}


#endif /* MARKED_H_ */
