/*
 * ValidationProcessor.h
 *
 *  Created on: 7 Nis 2018
 *      Author: emreyilmaz
 */

#ifndef VALIDATIONPROCESSOR_H_
#define VALIDATIONPROCESSOR_H_

#include <list>
#include "Line.h"
#include <fstream>
#include "Util.h"
#include "Constant.h"
using namespace std;

class ValidationProcessor {
public:
	ValidationProcessor();
	virtual ~ValidationProcessor();
	static list<Line> readAndValidateInput(int argc, char* argv[]);
};

#endif /* VALIDATIONPROCESSOR_H_ */
