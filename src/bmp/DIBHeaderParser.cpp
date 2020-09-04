#include "DIBHeaderParser.hpp"

DIBHeaderParser::DIBHeaderParser(const string& str) {
	this->_str = str;

	uint32_t* bitmapArrayWidth = (uint32_t*) str.substr(LOCATION_OF_BITMAP_ARRAY_WIDTH,
			 NUM_BYTES_OF_THE_OTHER_FIELDS).data();

	uint32_t* bitmapArrayHeight = (uint32_t*) str.substr(LOCATION_OF_BITMAP_ARRAY_HEIGHT,
			NUM_BYTES_OF_THE_OTHER_FIELDS).data();

	uint16_t* bitsPerPixel = (uint16_t*) str.substr(LOCATION_OF__BITS_PER_PIXEL,
			NUM_BYTES_OF_BITS_PER_PIXEL).data();

	uint32_t* numColorsInColorPalette = (uint32_t*) str.substr(LOCATION_OF_NUM_COLORS_IN_COLOR_PALETTE,
			NUM_BYTES_OF_THE_OTHER_FIELDS).data();

	this->_bitmapArrayWidth = *bitmapArrayWidth;
	this->_bitmapArrayHeight = *bitmapArrayHeight;
	this->_bitsPerPixel = *bitsPerPixel;
	this->_numColorsInColorPalette = *numColorsInColorPalette;
}

const string& DIBHeaderParser::getStr() const {
	return this->_str;
}

uint32_t DIBHeaderParser::getBitArrayWidth() const {
	return this->_bitmapArrayWidth;
}

uint32_t DIBHeaderParser::getBitArrayHeight() const {
	return this->_bitmapArrayHeight;
}

uint32_t DIBHeaderParser::getBitsPerPixel() const {
	return this->_bitsPerPixel;
}

uint32_t DIBHeaderParser::getNumColorsInColorPalette() const {
	return this->_numColorsInColorPalette;
}

void DIBHeaderParser::switchHeightAndWidth(){
	string height = this->_str.substr(LOCATION_OF_BITMAP_ARRAY_HEIGHT,
			NUM_BYTES_OF_THE_OTHER_FIELDS);
	string width = this->_str.substr(LOCATION_OF_BITMAP_ARRAY_WIDTH,
			 NUM_BYTES_OF_THE_OTHER_FIELDS);

	this->_str.replace(LOCATION_OF_BITMAP_ARRAY_HEIGHT,
			NUM_BYTES_OF_THE_OTHER_FIELDS, width);
	
	this->_str.replace(LOCATION_OF_BITMAP_ARRAY_WIDTH,
			 NUM_BYTES_OF_THE_OTHER_FIELDS, height);
}