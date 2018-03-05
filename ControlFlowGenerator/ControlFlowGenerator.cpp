// ControlFlowGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Line.h"
#include "Constant.h"
#include "BasicBlock.h"
#include "Util.h"

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <stack> 

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) {
		// Tell the user how to run the program
		cerr << "Usage: " << argv[0] << "<file_path>" << endl;
		return 1;
	}

	// Print the file path:
	cout << "BASIC BLOCKS"<< endl;
	cout << "-------------" << endl;

	//Create a list to store asic blocks
	list<BasicBlock> basicBlocks;

	//Create a file stream
	ifstream sourceCode(argv[1]);

	//Create first basic block
	BasicBlock startBasicBlock;
	Line startLine(0, "START");
	startBasicBlock.addLine(startLine);
	basicBlocks.push_back(startBasicBlock);

	//Create a basic block to point current one
	BasicBlock bk = *new BasicBlock();

	string line;
	int lineNumber = 1;
	
	//Read file line by line
	while (getline(sourceCode, line))
	{
		//Trim line
		string trimmedLine = Util::trim(line);
		
		//Create a new Line object
		Line newLine(lineNumber, trimmedLine);

		if (trimmedLine.find(Constant::KEYWORD_IF) != string::npos) {
			newLine.setLineType(Constant::LINE_TYPE_IF);
			bk.addLine(newLine);
			basicBlocks.push_back(bk);

			bk = *new BasicBlock();
		}
		else if (trimmedLine.find(Constant::KEYWORD_WHILE) != string::npos) {
			newLine.setLineType(Constant::LINE_TYPE_WHILE);
			basicBlocks.push_back(bk);

			bk = *new BasicBlock();
			bk.addLine(newLine);
			basicBlocks.push_back(bk);

			bk = *new BasicBlock();
		}
		else if (trimmedLine.find(Constant::KEYWORD_CLOSE_BRACKET) != string::npos) {
			basicBlocks.push_back(bk);
			bk = *new BasicBlock();
		}
		else if (trimmedLine.find(Constant::KEYWORD_ELSE) != string::npos) {
			//do nothing
		}
		else {
			newLine.setLineType(Constant::LINE_TYPE_EXPRESSION);
			bk.addLine(newLine);
		}

		//increase the line number
		lineNumber++;
	}

	//Create last basic block
	BasicBlock endBasicBlock;
	Line endLine(0, "END");
	endBasicBlock.addLine(endLine);
	basicBlocks.push_back(endBasicBlock);

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

	return 0;
}

