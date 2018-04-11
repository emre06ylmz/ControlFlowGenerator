/*
 * Util.cpp
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#include "Util.h"

Util::Util() {
	// TODO Auto-generated constructor stub

}

Util::~Util() {
	// TODO Auto-generated destructor stub
}

string Util::trim(const string& str)
{
	std::locale loc;
	std::string str_no_ws;
	for (char c : str) if (!std::isspace(c, loc)) str_no_ws += c;
	return str_no_ws;
}

BasicBlock Util::createStartBasicBlock(){
	BasicBlock startBasicBlock = BasicBlock(-1);
	Line startLine(0, "START");
	startBasicBlock.addLine(startLine);
	startBasicBlock.setLineType(Constant::LINE_TYPE_START);
	return startBasicBlock;
}

BasicBlock Util::createEndBasicBlock() {
	BasicBlock endBasicBlock = BasicBlock(-2);
	Line endLine(0, "END");
	endBasicBlock.addLine(endLine);
	endBasicBlock.setLineType(Constant::LINE_TYPE_END);
	return endBasicBlock;
}

