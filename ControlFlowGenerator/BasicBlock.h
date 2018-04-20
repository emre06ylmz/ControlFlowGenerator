/*
 * BasicBlock.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef BASICBLOCK_H_
#define BASICBLOCK_H_

#include <list>
#include <iostream>
#include "Line.h"
#include "Constant.h"

using namespace std;

class BasicBlock {
public:
	BasicBlock();
	BasicBlock(int _number);
	virtual ~BasicBlock();
	list<Line> getLines();
	void addLine(Line line);
	list<int> getEdges();
	void addEdge(int basicBlock);
	int getLineType();
	void setLineType(int _lineType);
	int getNumber();
	void setNumber(int _number);
	bool getIsLabel();
	void setIsLabel(bool _isLabel);
	bool getIsClosedl();
	void setIsClosed(bool _isClosedl);

private:
	list<Line> lines;
	list<int> edges;
	int lineType;
	int number;
	bool isLabel;
	bool isClosed;
};

#endif /* BASICBLOCK_H_ */
