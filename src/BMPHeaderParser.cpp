#include "BMPHeaderParser.hpp"

BMPHeaderParser::BMPHeaderParser(const string& str) {
	this->_str = str;

	if(str[0] != 'B' && str[1] != 'M'){
		cout<<"Error: BMPHeaderParser Constructor: This isn't a BMP file"<<endl;
	}

	uint32_t* size = (uint32_t*) str.substr(LOCATION_OF_SIZE,
			NUM_BYTES_OF_SIZE_AND_OFFSET).data();

	uint32_t* offset = (uint32_t*) str.substr(LOCATION_OF_OFFSET,
			NUM_BYTES_OF_SIZE_AND_OFFSET).data();

	this->_size = *size;
	this->_offset = *offset;
}

const string& BMPHeaderParser::getStr() const {
	return this->_str;
}

uint32_t BMPHeaderParser::getSize() const {
	return this->_size;
}

uint32_t BMPHeaderParser::getOffset() const {
	return this->_offset;
}
