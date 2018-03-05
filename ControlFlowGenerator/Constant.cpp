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

int Constant::LINE_TYPE_IF = 1;
int Constant::LINE_TYPE_WHILE = 2;
int Constant::LINE_TYPE_EXPRESSION = 3;