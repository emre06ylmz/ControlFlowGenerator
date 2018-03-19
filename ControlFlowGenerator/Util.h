#pragma once

#include <string>
#include "BasicBlock.h"
#include "Constant.h"
#include <locale>

using namespace std;

class Util
{

public:
	Util();
	~Util();

	static string trim(const string& str);
	static BasicBlock createStartBasicBlock();
	static BasicBlock createEndBasicBlock();

};

