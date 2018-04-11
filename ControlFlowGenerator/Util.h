/*
 * Util.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <string>
#include "BasicBlock.h"
#include "Constant.h"
#include <locale>
using namespace std;

class Util {
public:
	Util();
	virtual ~Util();
	static string trim(const string& str);
	static BasicBlock createStartBasicBlock();
	static BasicBlock createEndBasicBlock();
};

#endif /* UTIL_H_ */
