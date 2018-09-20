/*
 * ByteArray.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: dean
 */
#include <fstream>
#include "ByteArray.h"

ByteArray::ByteArray():_length(0),_data(NULL) {
}

ByteArray::ByteArray(unsigned long length):
		_length(length),_data(new char[length]) {
}

ByteArray::ByteArray(std::string file_name) {
	// Open new file stream
	std::fstream asset_file (file_name, std::ios::in | std::ios::binary);
	// Find file size
    asset_file.seekg (0, asset_file.end);
    unsigned int length = asset_file.tellg();
    asset_file.seekg (0, asset_file.beg);
    _length=length;
    // Allocate data
    _data=new char[_length];
    //Read in data
    asset_file.read (_data, length);
}

char* ByteArray::data() const {
	return _data;
}

ByteArray::~ByteArray() {
	_length = 0;
	delete _data;
}




