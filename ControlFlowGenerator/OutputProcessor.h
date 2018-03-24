#pragma once

#include "BasicBlock.h"
#include <list>
#include <iostream>

using namespace std;

class OutputProcessor
{
public:
	OutputProcessor();
	~OutputProcessor();

	static void outputBasicBlocks(list<BasicBlock> basicBlocks);

};



