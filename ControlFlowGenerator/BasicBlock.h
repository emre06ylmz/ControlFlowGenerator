#pragma once

#include <list>
#include "Line.h"

using namespace std;

class BasicBlock
{

public:
	BasicBlock();
	~BasicBlock();

	list<Line> getLines();
	void addLine(Line line);

	list<BasicBlock> getEdges();
	void addEdge(BasicBlock basicBlock);

	int getLineType();
	void setLineType(int _lineType);
private:
	list<Line> lines;
	list<BasicBlock> edges;
	int lineType;

};

