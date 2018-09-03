/*
 * LambdaTemplate.h
 *
 *  Created on: Sep 1, 2018
 *      Author: dean
 */

#ifndef LAMBDATEMPLATE_H_
#define LAMBDATEMPLATE_H_

#include <iostream>

template<typename T>
class RuncipleSpoon {
	typedef T* Tp;
	typedef Tp (*Tfp)(void*) ;
	T something;
	Tfp _func_ptr;
public:
	RuncipleSpoon<T>(T _something, Tfp _some_func_ptr):
		something(_something){
		this->_func_ptr=_some_func_ptr;
		T* that_thing = _func_ptr(&something);
		std::cout<<(*that_thing)<<std::endl;
	};
	virtual ~RuncipleSpoon(){}

	Tfp getFuncPtr() const {
		return _func_ptr;
	}

	void setFuncPtr(Tfp funcPtr) {
		_func_ptr = funcPtr;
	}

	T getSomething() const {
		return something;
	}

	void setSomething(T something) {
		this->something = something;
	}

	Tp runFuncPtr(void *payload){
		return _func_ptr(payload);
	}
};




#endif /* LAMBDATEMPLATE_H_ */
