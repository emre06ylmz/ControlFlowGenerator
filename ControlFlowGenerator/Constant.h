#pragma once

#include <string>
using namespace std;

class Constant
{


public:
	Constant();
	~Constant();

	static string KEYWORD_IF;
	static string KEYWORD_ELSE;
	static string KEYWORD_WHILE;
	static string KEYWORD_CLOSE_BRACKET;

	static int LINE_TYPE_IF;
	static int LINE_TYPE_WHILE;
	static int LINE_TYPE_EXPRESSION;
};

