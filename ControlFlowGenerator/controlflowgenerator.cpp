//============================================================================
// Name        : controlflowgenerator.cpp
// Author      : Eylmz
// Version     :
// Copyright   : Eylmz
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Line.h"
#include "Constant.h"
#include "BasicBlock.h"
#include "Util.h"
#include "ValidationProcessor.h"
#include "BasicBlockProcessor.h"
#include "OutputProcessor.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stack>

using namespace std;

int main(int argc, char* argv[]) {

	//read lines
	list<Line> lines = ValidationProcessor::readAndValidateInput(argc, argv);

	//create basic blocks
	list<BasicBlock> basicBlocksSimple = BasicBlockProcessor::createBasicBlocks(lines);

	//create basic block edges
	list<BasicBlock> basicBlocks = BasicBlockProcessor::createEdges(basicBlocksSimple);

	// Print the file path:
	OutputProcessor::outputBasicBlocks(basicBlocks);

	OutputProcessor::outputBasicBlocksDetailed(basicBlocks);

	OutputProcessor::outputBasicBlockEdges(basicBlocks);

	OutputProcessor::outputPaths(basicBlocks);

	return 0;
}
