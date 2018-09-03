/*
 * TestSpork.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: dean
 */

#include "TestSpork.h"

TestSpork::TestSpork() {
	Spork<std::string>("Platypus");
	Spork<double>(3.14159);
	Spork<long>(2L<<31L);
}

TestSpork::~TestSpork() {
	// TODO Auto-generated destructor stub
}

