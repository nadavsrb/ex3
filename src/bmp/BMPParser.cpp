#include "BMPParser.hpp"

#include <string>
using std::string;

BMPParser::BMPParser(const string& str) {
	this->_str = str;
	this->_BHparser = new BMPHeaderParser(str.substr(0, 14));
	this->_DIBparser = new DIBHeaderParser(str.substr(14, 40));

	uint32_t arrayOffset = this->_BHparser->getOffset();
	if (this->_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		
		this->_BMAparser = new BMArrayParserToMatrixes(str.substr(arrayOffset, str.length() - arrayOffset),
		this->_DIBparser->getBitArrayWidth(), this->_DIBparser->getBitArrayHeight());

	} else if (this->_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
		this->_CTparser = new ColorTableParser(str.substr(54, 1024));//2^8*4=1024

		this->_BMAColorparser = new BMArrayWithColorPattle(str.substr(arrayOffset, str.length() - arrayOffset),
		this->_DIBparser->getBitArrayWidth(), this->_DIBparser->getBitArrayHeight(), this->_CTparser);

	} else { 
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
	}
}

const string& BMPParser::getBMP() const {
	return this->_str;
}

void BMPParser::imageToGray(){
	
	uint32_t arrayOffset = this->_BHparser->getOffset();
	if (this->_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
	this->_BMAparser->changeToGray();

	this->_str.replace(arrayOffset, this->_str.length() - arrayOffset, this->_BMAparser->getStr());
	} else if (this->_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
	this->_BMAColorparser->changeToGray();

	this->_str.replace(54, 1024, this->_CTparser->getStr());
	} else { 
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
	}
}

void BMPParser::rotateImage() {
	uint32_t arrayOffset = this->_BHparser->getOffset();
	this->_DIBparser->switchHeightAndWidth();
	this->_str.replace(14, 40, this->_DIBparser->getStr());
	if (this->_DIBparser->getBitsPerPixel() == 24) { //if 24 bits per pixel
		this->_BMAparser->rotate();

		this->_str.replace(arrayOffset, this->_str.length() - arrayOffset, this->_BMAparser->getStr());
	} else if (this->_DIBparser->getBitsPerPixel() == 8) {//if 8 bits per pixel
	this->_BMAColorparser->rotate();

	this->_str.replace(arrayOffset, this->_str.length() - arrayOffset, this->_BMAColorparser->getStr());
	} else { 
		cout<<"Error: BMPParser Constructor: the bits per pixel arn't 8 or 24"<<endl;
	}
}