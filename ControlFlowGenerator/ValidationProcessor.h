#pragma once

#include <list>
#include "Line.h"
#include <fstream>
#include "Util.h"
#include "Constant.h"

using namespace std;

class ValidationProcessor
{
public:
	ValidationProcessor();
	~ValidationProcessor();

	static list<Line> readAndValidateInput(int argc, char* argv[]);
};

