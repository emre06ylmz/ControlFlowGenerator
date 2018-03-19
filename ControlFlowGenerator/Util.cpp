#include "stdafx.h"
#include "Util.h"

using namespace std;

Util::Util()
{
}

Util::~Util()
{
}

string Util::trim(const string& str)
{
	std::locale loc;
	std::string str_no_ws;
	for (char c : str) if (!std::isspace(c, loc)) str_no_ws += c;
	return str_no_ws;
}

BasicBlock Util::createStartBasicBlock(){
	BasicBlock startBasicBlock;
	Line startLine(0, "START");
	startBasicBlock.addLine(startLine);
	startBasicBlock.setLineType(Constant::LINE_TYPE_EXPRESSION);
	return startBasicBlock;
}

BasicBlock Util::createEndBasicBlock() {
	BasicBlock endBasicBlock;
	Line endLine(0, "END");
	endBasicBlock.addLine(endLine);
	endBasicBlock.setLineType(Constant::LINE_TYPE_EXPRESSION);
	return endBasicBlock;
}