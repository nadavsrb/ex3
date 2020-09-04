#include "Color.hpp"

Color::Color(uint16_t R, uint16_t G, uint16_t B) {
	this->_R = R;
	this->_G = G;
	this->_B = B;
}

uint16_t Color::getR() const {
	return this->_R;
}

uint16_t Color::getG() const {
	return this->_G;
}

uint16_t Color::getB() const {
	return this->_B;
}

void Color::toGray() {
	uint16_t gray = (uint16_t) (0.2126 * this->_R + 0.7152 * this->_G + 0.0722 * this->_B);

	this->_R = gray;
	this->_G = gray;
	this->_B = gray;
}
