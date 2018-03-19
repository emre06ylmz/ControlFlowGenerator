#include "stdafx.h"
#include "ValidationProcessor.h"
#include <iostream>

ValidationProcessor::ValidationProcessor()
{
}

ValidationProcessor::~ValidationProcessor()
{
}

list<Line> ValidationProcessor::readAndValidateInput(int argc, char* argv[]) {

	list<Line> lines;

	//control program argument
	if (argc < 2) {
		// Tell the user how to run the program
		cerr << "Usage: " << argv[0] << "<file_path>" << endl;
		return lines;
	}


	//contol first line of the program


	//Create a file stream
	ifstream sourceCode(argv[1]);
	string line;
	int lineNumber = 1;
	//Read file line by line
	while (getline(sourceCode, line))
	{
		//Trim line
		string trimmedLine = Util::trim(line);

		//if line is a comment ignore it
		if (trimmedLine.find(Constant::KEYWORD_COMMENT_BLOCK) != string::npos ||
			trimmedLine.find(Constant::KEYWORD_COMMENT_LINE_START) != string::npos ||
			trimmedLine.find(Constant::KEYWORD_COMMENT_LINE_END) != string::npos) {
			continue;
		}
		else {
			//Create a new Line object
			Line newLine(lineNumber, trimmedLine);

			lines.push_back(newLine);

			//increase the line number
			lineNumber++;
		}

	}


	//control and remove function signutre
	lines.pop_front();

	//remove last bracket
	lines.pop_back();

	return lines;
}
