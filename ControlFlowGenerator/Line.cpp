/*
 * Line.cpp
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#include "Line.h"

Line::Line() {
	// TODO Auto-generated constructor stub

}

Line::Line(int _lineNumber, string _expression) {
	lineNumber = _lineNumber;
	expression = _expression;
	lineType = 0;
}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

int Line::getLineNumber() {
	return lineNumber;
}
string Line::getExpression() {
	return expression;
}

int Line::getLineType() {
	return lineType;
}

void Line::setLineType(int _lineType) {
	lineType = _lineType;
}
