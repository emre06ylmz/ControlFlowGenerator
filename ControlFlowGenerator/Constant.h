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

	static string KEYWORD_COMMENT_BLOCK;
	static string KEYWORD_COMMENT_LINE_START;
	static string KEYWORD_COMMENT_LINE_END;

	static int LINE_TYPE_IF;
	static int LINE_TYPE_ELSE;
	static int LINE_TYPE_WHILE;
	static int LINE_TYPE_EXPRESSION;
	static int LINE_TYPE_CLOSE;

};

