#include "stdafx.h"
#include "BasicBlock.h"

using namespace std;

BasicBlock::BasicBlock()
{
}

list<Line> BasicBlock::getLines() {
	return lines;
}

list<BasicBlock> BasicBlock::getEdges() {
	return edges;
}

void BasicBlock::addLine(Line line) {
	lines.push_back(line);
}

void BasicBlock::addEdge(BasicBlock basicBlock) {
	edges.push_back(basicBlock);
}

BasicBlock::~BasicBlock()
{
}
