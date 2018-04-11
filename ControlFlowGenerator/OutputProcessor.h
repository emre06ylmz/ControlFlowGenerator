/*
 * OutputProcessor.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef OUTPUTPROCESSOR_H_
#define OUTPUTPROCESSOR_H_

#include "BasicBlock.h"
#include <list>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class OutputProcessor {
public:
	OutputProcessor();
	virtual ~OutputProcessor();
	static void outputBasicBlocks(list<BasicBlock> basicBlocks);
	static void outputBasicBlocksDetailed(list<BasicBlock> basicBlocks);
	static void outputBasicBlockEdges(list<BasicBlock> basicBlocks);
	static void outputPaths(list<BasicBlock> basicBlocks);
	static void addPath(string previous, BasicBlock basicBlockList[], int index);
};

#endif /* OUTPUTPROCESSOR_H_ */
