#include "stdafx.h"
#include "Line.h"

using namespace std;

Line::Line() {
	lineNumber = 0;
	expression = "";
}

Line::Line(int _lineNumber, string _expression) {
	lineNumber = _lineNumber;
	expression = _expression;
	lineType = 0;
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

Line::~Line()
{
}
