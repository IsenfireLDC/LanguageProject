/*
 * Lang.h
 *
 *  Created on: Nov 21, 2018
 *      Author: Ben Klemp - temp
 */

#ifndef LANG_H_
#define LANG_H_

#include "TokenType.h"

namespace compiler {

struct op;

struct binop: op {
	Token op;
	Token out;
	Token in[2];
};

struct unop: op {
	Token op;
	Token out;
	Token in;
};

struct assign: op {
	Token op;
	Token type;
	Token name; //in
	expression value; //out  //TODO: See if this will work; add different type?
};

enum class LangType {
	Class,
	FuncCall,
	Func,
	Access,
	Bool,
	Int,
	Float,
	Double,
	String,
	Char,
	Object,
	Array,
	Name,
	Op,
	Modifier,
	Const,
	EOL, //end of line
	EOB, //end of block
	BOB, //beginning of block
	EOI  //end of input(file)
};

string reservedWords[] = {
		"class",
		"in",
		"extends",
		"is",
		"new",
		"true",
		"false",
		"null",
		"this"
};

char typeChars[] = {
		//access
		'p',
		'h',
		//type
		'b',
		'i',
		'f',
		'd',
		's',
		'a',
		'c',
		//modifier
		'e',
		'o',
		't'
};

class LangToken {
public:
	LangToken();

	Token token;
	LangType type;

};

/*
 * Example program:
 *
 * class:
 * <*access> class <name> [*in <namespace>] [*extends <class><*,class>] [is <s-type>] {}
 *
 * variable:
 * <type> <name>;
 * <type> <name> = <value>;
 * <type> <name> = <expression>;
 *
 * field:
 * <*object> <*access> <variable>
 *
 * access:
 * public: p
 * private(hidden): h
 *
 * types:
 * bool: b
 * int: i
 * float: f
 * double: d
 * string: s
 * object: <type>
 * array: a or [<size>]
 * char: c
 *
 * modifiers:
 * final(end): e
 * static(only): o
 * s-type(special handling): t<s-type>
 *
 * decl-values:
 * <num as <int>/<float>/<double>>
 * <string as ""/{''}>
 * <object as new <type>>
 * <array as {}>
 * <char as ''>
 * <bool as true/false>
 * <any as null/<default>/<s-type>>
 *
 * constants/keywords:
 * <int/float/double>
 * <""/''>
 * true/false
 * null
 * this[obj pointer]
 *
 * operators:
 * <compare as >/</>=/<=/==>
 * <binop as <compare>/+/-/* or />
 * <unop as -/--/++>
 * <assign as =/+=/-=/*= or /=>
 *
 * compile to c++
 *
 * **program start**
 * s str = "Hello, world";
 * s strin = in(s); /or/ s strin = in();
 * public class myclass in myclasses extends mybaseclass, myotherclass {
 *   pi num = 100;  --> int num = 100;
 *   num += 5;  -->  num += 5;
 *   out(num);  -->  cout << num << endl;
 *   i[3] nums = {0, 1, 2};  -->  int temp[4] = {3, 0, 1, 2};int* nums = &temp[1];
 *   hs str = strin;
 *   ps strout() {
 *     return <hs> this.str;
 *   }
 * };
 * myclass inst = new myclass();
 * inst ps str = str;
 * out(inst.str);  o=> "Hello, world"
 * out(inst.strout); o=> <strin>
 * **program end**
 *
*/

}


#endif /* LANG_H_ */
