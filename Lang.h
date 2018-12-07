/*
 * Lang.h
 *
 *  Created on: Nov 21, 2018
 *      Author: Ben Klemp
 */

#ifndef LANG_H_
#define LANG_H_

#include "TokenType.h"

#include <vector>
#include <iostream>
//#include <algorithm>

using namespace std;

namespace compiler {

enum class LangType {
	Basic,
	//classes/functions/methods
	Class,
	Space,
	Extend,
	FuncCall,
	Func,
	Access,
	//types
	Bool,
	Int,
	Float,
	Double,
	String,
	Char,
	//literals
	Num,
	LString,
	CChar,
	//object/array
	New,
	Object,
	Array,
	//variable name
	Name,
	//operators/modifiers
	Op,
	Modifier,
	//TODO:Const,
	EOL, //end of line
	EOB, //end of block
	BOB, //beginning of block
	EOI,  //end of input(file)
	Null = -1,
	Unrecognized = -2
};

void f(Token*);

/*for_each(params.begin(), params.end(), f);*/

class op {
public:
	op(Token*);

	LangType type = LangType::Null;

	Token get_op();

private:
	Token op_token;
};

class basicop: public op {
public:
	basicop(Token*);

	LangType type = LangType::Basic;

	void add_param(Token*);
	vector<Token> get_params();

private:
	vector<Token> params;
};

LangType getReservedType(Token);

bool isEndOfStatement(Token);

extern string reservedWords[2];

extern char typeChars[12];

class LangToken {
public:
	LangToken(Token, LangType);

	Token token;
	LangType type;

	unsigned int position = 0;

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
 * <compare as > / < / >= / <= / ==>
 * <binop as <compare> / + / - / * or />
 * <unop as - / -- / ++>
 * <assign as = / += / -= / *= or /=>
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
