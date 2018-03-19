#include "stdafx.h"
#include "Line.h"

using namespace std;

Line::Line() {
}

Line::Line(int _lineNumber, string _expression) {
	lineNumber = _lineNumber;
	expression = _expression;
	lineType = 0;
}

Line::~Line()
{
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
