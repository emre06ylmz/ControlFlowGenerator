#pragma once

#include <string>
using namespace std;

class Line
{


public:
	Line();
	Line(int _lineNumber, string _expression);
	~Line();

	int getLineNumber();
	string getExpression();
	int getLineType();
	void setLineType(int _lineType);
private: 
	int lineNumber;
	string expression;
	int lineType;
};

