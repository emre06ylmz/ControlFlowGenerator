#pragma once

#include <list>
#include "BasicBlock.h"
#include "Line.h"
#include <fstream>
#include "Util.h"
#include "Constant.h"

using namespace std;

class BasicBlockProcessor
{
public:
	BasicBlockProcessor();
	~BasicBlockProcessor();

	static list<BasicBlock> createBasicBlocks(list<Line>);

	static list<BasicBlock> createEdges(list<BasicBlock>);
};

