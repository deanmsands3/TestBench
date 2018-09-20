#ifndef __BYTE_ARRAY_H__
#define __BYTE_ARRAY_H__

#include <string>

class ByteArray{
	unsigned long _length;
	char* _data;
public:
	char* data() const;
	ByteArray();
	ByteArray(unsigned long length);
	ByteArray(std::string file_name);
	~ByteArray();
};

#endif
