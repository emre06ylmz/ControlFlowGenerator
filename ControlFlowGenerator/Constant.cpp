#include "stdafx.h"
#include "Constant.h"

Constant::Constant()
{
}

Constant::~Constant()
{
}

string Constant::KEYWORD_IF = "if(";
string Constant::KEYWORD_ELSE = "else";
string Constant::KEYWORD_WHILE = "while(";
string Constant::KEYWORD_CLOSE_BRACKET = "}";

string Constant::KEYWORD_COMMENT_BLOCK = "//";
string Constant::KEYWORD_COMMENT_LINE_START = "/*";
string Constant::KEYWORD_COMMENT_LINE_END = "*/";

int Constant::LINE_TYPE_IF = 1; 
int Constant::LINE_TYPE_ELSE = 2;
int Constant::LINE_TYPE_WHILE = 3; 
int Constant::LINE_TYPE_EXPRESSION = 4;
int Constant::LINE_TYPE_CLOSE = 5;