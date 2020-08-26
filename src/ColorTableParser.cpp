#include "ColorTableParser.hpp"

ColorTableParser::ColorTableParser(const string& str) {
	this->_str = str;
	for (uint32_t i = 0; i < str.length(); ++i) {
		uint16_t* r = (uint16_t*) str.substr(i, 1).data();
		++i;
		uint16_t* g = (uint16_t*) str.substr(i, 1).data();
		++i;
		uint16_t* b = (uint16_t*) str.substr(i, 1).data();
		++i;
		this->_colors.push_back(new Color(*r, *g, *b));
	}
}

const string& ColorTableParser::getStr() const {
	return this->_str;
}

uint32_t ColorTableParser::getColorCount() const {
	return this->_colors.size();
}

Color ColorTableParser::getColor(uint32_t n) const {
	return *(this->_colors.at(n));
}

vector<Color*> ColorTableParser::getColors() const {
	return this->_colors;
}

void ColorTableParser::changeColorToGray(uint32_t n) {
	this->_colors.at(n)->toGray();
	uint16_t color;
    char* c;
   	string s;

 	//then because we did "this->_colors.at(n)->toGray()"
	// R = 0 G = 0 B = 0 so it's black and no need change
	if(this->_colors.at(n)->getR() != 0){
	//each color takes 4 bits that the first 3 are: R G B.
	color = (uint16_t) this->_colors.at(n)->getR();
    c = (char*) &color;
   	s = c;
	this->_str.replace(n*4, 1, s); //n*4 the loction the bit starts from.
	color = (uint16_t) this->_colors.at(n)->getG();
    c = (char*) &color;
   	s = c;
	this->_str.replace(n*4 + 1, 1, s); //n*4 the loction the bit starts from.

	color = (uint16_t) this->_colors.at(n)->getB();
    c = (char*) &color;
   	s = c;
	this->_str.replace(n*4 + 2, 1, s); //n*4 the loction the bit starts from.
	}
}

ColorTableParser::~ColorTableParser(){
	for (uint32_t i = 0; i < this->_colors.size(); ++i){
		delete this->_colors.at(i);
	}
}