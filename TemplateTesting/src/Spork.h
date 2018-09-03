/*
 * Spork.h
 *
 *  Created on: Sep 1, 2018
 *      Author: dean
 */

#ifndef SPORK_H_
#define SPORK_H_

#include <iostream>

template<typename T>
class Spork {
	T something;
public:
	Spork<T>(T _something):something(_something){
		std::cout<<something<<std::endl;
	};
	virtual ~Spork(){}
};

#endif /* SPORK_H_ */
