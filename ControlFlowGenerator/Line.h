/*
 * Line.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef LINE_H_
#define LINE_H_

#include <string>
#include <iostream>
using namespace std;

class Line {
public:
	Line();
	Line(int _lineNumber, string _expression);
	virtual ~Line();
	int getLineNumber();
	string getExpression();
	int getLineType();
	void setLineType(int _lineType);

private:
	int lineNumber;
	string expression;
	int lineType;
};

#endif /* LINE_H_ */
