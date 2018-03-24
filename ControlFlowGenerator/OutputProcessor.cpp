#include "stdafx.h"
#include "OutputProcessor.h"


OutputProcessor::OutputProcessor()
{
}


OutputProcessor::~OutputProcessor()
{
}

void OutputProcessor::outputBasicBlocks(list<BasicBlock> basicBlocks) {
	// Print the file path:
	cout << "BASIC BLOCKS" << endl;
	cout << "-------------" << endl;

	//Iterate all basic blocks
	for (list<BasicBlock>::iterator iterator = basicBlocks.begin(); iterator != basicBlocks.end(); ++iterator) {
		BasicBlock currentBasicBlock = (*iterator);
		list<Line> currentLineList = currentBasicBlock.getLines();


		 //Iterate all lines of current basic block
		for (list<Line>::iterator it = currentLineList.begin(); it != currentLineList.end(); ++it) {
			Line current = (*it);
			cout << current.getExpression() << endl;
		}
		cout << "" << "" << "" << endl;
	}

}
