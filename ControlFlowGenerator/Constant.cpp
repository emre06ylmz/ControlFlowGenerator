/*
 * Constant.cpp
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#include "Constant.h"

Constant::Constant() {
	// TODO Auto-generated constructor stub

}

Constant::~Constant() {
	// TODO Auto-generated destructor stub
}

string Constant::KEYWORD_IF = "if(";
string Constant::KEYWORD_ELSE = "else";
string Constant::KEYWORD_RETURN = "return";

string Constant::KEYWORD_WHILE = "while(";
string Constant::KEYWORD_FOR = "for(";
string Constant::KEYWORD_CLOSE_BRACKET = "}";

string Constant::KEYWORD_COMMENT_BLOCK = "//";
string Constant::KEYWORD_COMMENT_LINE_START = "/*";
string Constant::KEYWORD_COMMENT_LINE_END = "*/";

int Constant::LINE_TYPE_EXPRESSION = 0;
int Constant::LINE_TYPE_IF = 1;
int Constant::LINE_TYPE_IF_PREVIOUS = 2;
int Constant::LINE_TYPE_ELSE = 3;
int Constant::LINE_TYPE_ELSE_PREVIOUS = 4;
int Constant::LINE_TYPE_LOOP = 5;
int Constant::LINE_TYPE_LOOP_PREVIOUS = 6;
int Constant::LINE_TYPE_LOOP_CLOSE = 7;
int Constant::LINE_TYPE_CLOSE = 8;

int Constant::LINE_TYPE_START = 9;
int Constant::LINE_TYPE_END = 10;
