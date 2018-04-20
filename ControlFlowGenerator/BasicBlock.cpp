/*
 * BasicBlock.cpp
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#include "BasicBlock.h"

BasicBlock::BasicBlock() {
	// TODO Auto-generated constructor stub
	lineType = Constant::LINE_TYPE_EXPRESSION;
	isLabel = false;
	isClosed = false;
}

BasicBlock::BasicBlock(int _number) {
	// TODO Auto-generated constructor stub
	number = _number;
	isLabel = false;
	isClosed = false;
}

BasicBlock::~BasicBlock() {
	// TODO Auto-generated destructor stub
}

list<Line> BasicBlock::getLines() {
	return lines;
}

list<int> BasicBlock::getEdges() {
	return edges;
}

void BasicBlock::addLine(Line line) {
	lines.push_back(line);
}

void BasicBlock::addEdge(int basicBlock) {
	bool isFound = false;
	for (list<int>::iterator iteratorEdge = edges.begin(); iteratorEdge != edges.end(); ++iteratorEdge) {
		int newIndex = (*iteratorEdge);
		if(newIndex == basicBlock){
			isFound = true;
		}
	}
	if(isFound == false){
		edges.push_back(basicBlock);
	}

}

int BasicBlock::getLineType() {
	return lineType;
}

void BasicBlock::setLineType(int _lineType) {
	lineType = _lineType;
}

int BasicBlock::getNumber() {
	return number;
}

void BasicBlock::setNumber(int _number) {
	number = _number;
}

bool BasicBlock::getIsLabel() {
	return isLabel;
}

void BasicBlock::setIsLabel(bool _isLabel) {
	isLabel = _isLabel;
}

bool BasicBlock::getIsClosedl() {
	return isClosed;
}

void BasicBlock::setIsClosed(bool _isClosed) {
	isClosed = _isClosed;
}
