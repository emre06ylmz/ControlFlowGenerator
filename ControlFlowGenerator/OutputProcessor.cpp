/*
 * OutputProcessor.cpp
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#include "OutputProcessor.h"

OutputProcessor::OutputProcessor() {
	// TODO Auto-generated constructor stub

}

OutputProcessor::~OutputProcessor() {
	// TODO Auto-generated destructor stub
}

void OutputProcessor::outputBasicBlocks(list<BasicBlock> basicBlocks) {
	cout << "N={";

	for (list<BasicBlock>::iterator iterator = basicBlocks.begin(); iterator != basicBlocks.end(); ++iterator) {
		list<Line> currentLineList = iterator->getLines();

		if(iterator->getLineType() == Constant::LINE_TYPE_START){
			cout << "Start,";
		} else if(iterator->getLineType() == Constant::LINE_TYPE_END){
			cout << "End";
		} else{
			cout << iterator->getNumber() << ",";
		}
	}
	cout << "}"<< endl;
}

void OutputProcessor::outputBasicBlocksDetailed(list<BasicBlock> basicBlocks) {
	// Print the file path:
	cout << "Basic Block Detail" << endl;
	//Iterate all basic blocks
	for (list<BasicBlock>::iterator iterator = basicBlocks.begin(); iterator != basicBlocks.end(); ++iterator) {
		list<Line> currentLineList = iterator->getLines();
		if(iterator->getNumber() > 0){
			cout << iterator->getNumber() << "		";
			 //Iterate all lines of current basic block
			for (list<Line>::iterator it = currentLineList.begin(); it != currentLineList.end(); ++it) {
				cout << it->getLineNumber() << " ";
			}
			cout << "" << "" << "" << endl;
		}
	}
}

void OutputProcessor::outputBasicBlockEdges(list<BasicBlock> basicBlocks) {
	//Iterate all basic blocks
	cout << "E={";
	for (list<BasicBlock>::iterator iterator = basicBlocks.begin(); iterator != basicBlocks.end(); ++iterator) {
		list<int> edges = iterator->getEdges();
		for (list<int>::iterator iteratorEdge = edges.begin(); iteratorEdge != edges.end(); ++iteratorEdge) {
			int value = (*iteratorEdge);
			if(iterator->getNumber() == -1){
				cout << "(Start," << value << ")";
			} else if(value == -2){
				cout << ", (" << iterator->getNumber() << ",End)";
			} else {
				cout << ", (" << iterator->getNumber() << "," << value << ")";
			}
		}
	}
	cout << "}" << endl;
}

void OutputProcessor::outputPaths(list<BasicBlock> basicBlocks){
	BasicBlock basicBlockList[basicBlocks.size()];

	int i = 0;
	for (list<BasicBlock>::iterator iterator = basicBlocks.begin(); iterator != basicBlocks.end(); ++iterator) {
		basicBlockList[i] = (*iterator);
		i++;
	}
	OutputProcessor::addPath("START", basicBlockList, 0);
}

void OutputProcessor::addPath(string previous, BasicBlock basicBlockList[], int index){
	BasicBlock block = basicBlockList[index];
	if(block.getLineType() == Constant::LINE_TYPE_END || block.getNumber() == -2){
		cout << previous << "-END"<< endl;
	} else {
		list<int> edges = block.getEdges();
		if(edges.size() == 0){
			cout << previous << " - ";
			cout << "-ERROR" << endl;
		} else{
			for (list<int>::iterator iteratorEdge = edges.begin(); iteratorEdge != edges.end(); ++iteratorEdge) {
				int newIndex = (*iteratorEdge);
				if(newIndex == -2){
					cout << previous << "-END"<< endl;
				} else if(newIndex > index) {
					std::stringstream ss;
					ss << previous << "-" << newIndex;
					std::string value = ss.str();

					//cout << "go: "<< iteratorEdge << " size:" << iteratorEdge->getEdges().size() << endl;
					OutputProcessor::addPath(value, basicBlockList, newIndex);
				} else{
					std::stringstream ss;
					ss << previous << "-" << newIndex;
					std::string value = ss.str();
					cout << value << "-LOOP" <<endl;
				}

			}
		}
	}
}

