/*
 * BasicBlockProcessor.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef BASICBLOCKPROCESSOR_H_
#define BASICBLOCKPROCESSOR_H_

#include <list>
#include "BasicBlock.h"
#include "Line.h"
#include <fstream>
#include "Util.h"
#include "Constant.h"
using namespace std;

class BasicBlockProcessor {
public:
	BasicBlockProcessor();
	virtual ~BasicBlockProcessor();
	static list<BasicBlock> createBasicBlocks(list<Line>);
	static list<BasicBlock> createEdges(list<BasicBlock>);
};

#endif /* BASICBLOCKPROCESSOR_H_ */
