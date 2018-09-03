//============================================================================
// Name        : TemplateTesting.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Spork.h"
#include "TestSpork.h"
#include "LambdaTemplate.h"

using namespace std;

int main() {
	Spork<int>(42);
	TestSpork();
	RuncipleSpoon<double>(3.14159,
		[](void *payload){
			double *dp=(double*)payload;
			*dp *=2.0;
			return dp;
		}
	);
	return 0;
}
