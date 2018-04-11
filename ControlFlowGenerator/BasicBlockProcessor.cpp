/*
 * BasicBlockProcessor.cpp
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#include "BasicBlockProcessor.h"

BasicBlockProcessor::BasicBlockProcessor() {
	// TODO Auto-generated constructor stub

}

BasicBlockProcessor::~BasicBlockProcessor() {
	// TODO Auto-generated destructor stub
}

list<BasicBlock> BasicBlockProcessor::createBasicBlocks(list<Line> lines) {
	list<BasicBlock> basicBlocks;

	Line newLine;
	int lineNumber;
	int basicBlockNumber = 1;
	BasicBlock currentBasicBlock;

	//initialize variables
	lineNumber = 0;
	currentBasicBlock = *new BasicBlock(basicBlockNumber);
	basicBlockNumber++;

	//Create first basic block
	BasicBlock startBasicBlock = Util::createStartBasicBlock();
	basicBlocks.push_back(startBasicBlock);

	for (list<Line>::iterator iterator = lines.begin(); iterator != lines.end(); ++iterator) {
		//Trim line
		newLine = (*iterator);
		string trimmedLine = newLine.getExpression();

		/* if */
		if (trimmedLine.find(Constant::KEYWORD_IF) != string::npos) {
			currentBasicBlock.setLineType(Constant::LINE_TYPE_IF_PREVIOUS);
			currentBasicBlock.addLine(newLine);
			basicBlocks.push_back(currentBasicBlock);

			currentBasicBlock = *new BasicBlock(basicBlockNumber);
			basicBlockNumber++;
			currentBasicBlock.setLineType(Constant::LINE_TYPE_IF);
		}
		/* while */
		else if (trimmedLine.find(Constant::KEYWORD_WHILE) != string::npos ||
				trimmedLine.find(Constant::KEYWORD_FOR) != string::npos) {
			currentBasicBlock.setLineType(Constant::LINE_TYPE_LOOP_PREVIOUS);
			basicBlocks.push_back(currentBasicBlock);

			currentBasicBlock = *new BasicBlock(basicBlockNumber);
			basicBlockNumber++;
			currentBasicBlock.setLineType(Constant::LINE_TYPE_LOOP);
			currentBasicBlock.addLine(newLine);
			basicBlocks.push_back(currentBasicBlock);

			currentBasicBlock = *new BasicBlock(basicBlockNumber);
			basicBlockNumber++;
		}
		/* else */
		else if (trimmedLine.find(Constant::KEYWORD_ELSE) != string::npos) {
			//basicBlocks.push_back(currentBasicBlock);
			//currentBasicBlock = *new BasicBlock(basicBlockNumber);
			//basicBlockNumber++;
			currentBasicBlock.setLineType(Constant::LINE_TYPE_ELSE);

			// TODO if there is no if closing tag handle it
		}
		/* close */
		else if (trimmedLine.find(Constant::KEYWORD_CLOSE_BRACKET) != string::npos) {
			//currentBasicBlock.setLineType(Constant::LINE_TYPE_CLOSE);
			basicBlocks.push_back(currentBasicBlock);
			currentBasicBlock = *new BasicBlock(basicBlockNumber);
			basicBlockNumber++;
			//cout << "KEYWORD_CLOSE_BRACKET: "<< currentBasicBlock.getNumber() << endl;
			// TODO if it is loop closing node, sign it
			int deep = 0;
			for (list<BasicBlock>::iterator iteratorSecond = basicBlocks.end(); iteratorSecond != basicBlocks.begin(); --iteratorSecond) {
				//if loop close
				if (iteratorSecond->getIsLabel() == true) {
					deep++;

					//cout << "deep: "<< iteratorSecond->getIsLabel() << endl;
				} else if (iteratorSecond->getLineType() == Constant::LINE_TYPE_LOOP) {
					if(deep == 0){
						currentBasicBlock.setLineType(Constant::LINE_TYPE_LOOP_CLOSE);
						currentBasicBlock.setIsLabel(true);
						iteratorSecond->addEdge(currentBasicBlock.getNumber());
						//cout << "deep addEdge: "<< iteratorSecond->getNumber() << " - " << currentBasicBlock.getNumber() << endl;
						continue;
					}else{
						deep--;
					}

				}
			}
		}
		/* basic line */
		else {
			currentBasicBlock.addLine(newLine);
			//cout << newLine.getExpression() << " " << currentBasicBlock.getNumber() << endl;
		}

		//increase the line number
		lineNumber++;
	}

	if(currentBasicBlock.getLineType() == Constant::LINE_TYPE_EXPRESSION){
		basicBlocks.push_back(currentBasicBlock);
	}

	//Create last basic block
	BasicBlock endBasicBlock = Util::createEndBasicBlock();
	basicBlocks.push_back(endBasicBlock);

	return basicBlocks;
}


list<BasicBlock> BasicBlockProcessor::createEdges(list<BasicBlock> basicBlocks) {
	//Iterate all basic blocks
	for (list<BasicBlock>::iterator iterator = basicBlocks.begin(); iterator != basicBlocks.end(); ++iterator) {

		list<Line> currentLineList = iterator->getLines();

		if (iterator->getLineType() == Constant::LINE_TYPE_START) {//start
			auto next = std::next(iterator, 1);
			iterator->addEdge(next->getNumber());
		} else if (iterator->getLineType() == Constant::LINE_TYPE_END) {//end
			auto prev = std::prev(iterator, 1);
			prev->addEdge(iterator->getNumber());
		} else{//at middle
			auto prev = std::prev(iterator, 1);
			if(iterator->getLineType() == Constant::LINE_TYPE_IF){//previous node if
				prev->addEdge(iterator->getNumber());
				// TODO create a stack to find true indentation
				for (list<BasicBlock>::iterator iteratorSecond = iterator; iteratorSecond != basicBlocks.end(); ++iteratorSecond) {
					if (iteratorSecond->getLineType() != Constant::LINE_TYPE_IF && iteratorSecond->getLineType() != Constant::LINE_TYPE_ELSE) {
						iterator->addEdge(iteratorSecond->getNumber());
						break;
					}
				}

			} else if(iterator->getLineType() == Constant::LINE_TYPE_ELSE){//previous node else
				//backtrack and find previous node before if
				// TODO create a stack to find true indentation
				for (list<BasicBlock>::iterator iteratorSecond = iterator; iteratorSecond != basicBlocks.begin(); --iteratorSecond) {
					if (iteratorSecond->getLineType() == Constant::LINE_TYPE_IF_PREVIOUS) {
						iteratorSecond->addEdge(iterator->getNumber());
					}
				}
				auto next = std::next(iterator, 1);
				iterator->addEdge(next->getNumber());
			} else if(iterator->getLineType() == Constant::LINE_TYPE_LOOP){//previous node if
				auto next = std::next(iterator, 1);
				prev->addEdge(iterator->getNumber());
				iterator->addEdge(next->getNumber());
			} else if(iterator->getLineType() == Constant::LINE_TYPE_LOOP_PREVIOUS){//previous node if
				//prev->addEdge((*iterator));
			}

		}
	}

	return basicBlocks;
}
