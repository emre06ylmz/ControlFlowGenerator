/*
 * Constant.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include <string>
using namespace std;

class Constant {
public:
	Constant();
	virtual ~Constant();
	static string KEYWORD_IF;
	static string KEYWORD_ELSE;
	static string KEYWORD_WHILE;
	static string KEYWORD_FOR;
	static string KEYWORD_CLOSE_BRACKET;

	static string KEYWORD_COMMENT_BLOCK;
	static string KEYWORD_COMMENT_LINE_START;
	static string KEYWORD_COMMENT_LINE_END;

	static int LINE_TYPE_IF;
	static int LINE_TYPE_IF_PREVIOUS;
	static int LINE_TYPE_ELSE;
	static int LINE_TYPE_ELSE_PREVIOUS;
	static int LINE_TYPE_LOOP;
	static int LINE_TYPE_LOOP_PREVIOUS;
	static int LINE_TYPE_LOOP_CLOSE;
	static int LINE_TYPE_EXPRESSION;
	static int LINE_TYPE_CLOSE;
	static int LINE_TYPE_START;
	static int LINE_TYPE_END;
};

#endif /* CONSTANT_H_ */
