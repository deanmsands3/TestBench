/*
 * ByteArray.cpp
 *
 *  Created on: Apr 2, 2018
 *      Author: dean
 */
#include <fstream>
#include <cstring>
#include "ByteArray.h"

ByteArray::ByteArray():_length(0),_data(NULL) {
}

ByteArray::ByteArray(unsigned long length):_length(length) {
	_data=std::make_shared<std::vector<char> >(length);
}

ByteArray::ByteArray(std::string file_name) {
	// Open new file stream
	std::ifstream asset_file (file_name, std::ios::binary|std::ios::ate);
	// Find file size
    //asset_file.seekg (0, asset_file.end);
    unsigned int length = asset_file.tellg();
    asset_file.seekg (0, asset_file.beg);
    _length=length;
    // Allocate data
    _data = std::make_shared<std::vector<char> >(length);
    char *ptr=(_data.get())->data();
    //Read in data
    asset_file.read (ptr, length);
    asset_file.exceptions(asset_file.failbit);
}

char* ByteArray::data() const {
	return _data.get()->data();
}

unsigned long ByteArray::length() const {
	return _length;
}

ByteArray::ByteArray(const ByteArray &that):_length(that._length),_data(that._data){
}

ByteArray::~ByteArray() {
	_length = 0;
}




