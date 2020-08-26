#include "BMArrayWithColorPattle.hpp"

BMArrayWithColorPattle::BMArrayWithColorPattle(const string& str, uint32_t width,
        uint32_t height, ColorTableParser* colorTable){
    this->_str = str;
	this->_width = width;
	this->_height = height;
	this->_matrix = new MatrixClass(height, width);
    this->_colorTable = colorTable;

	//calculating how much padding for width *1 (=nub bits to pixel) to be 4*int
	this->_bytesPeddingPerRow = (4 - ((width) % 4))%4;

	for (uint32_t row = 0; row < height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (width + _bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (height - 1) - row;
		for (uint32_t col = 0; col < width; ++col) {
			//startOfRaw in the matrix, col = num of pixel in the raw before (*1 = this size in the string)
			uint16_t* colorIndex = (uint16_t*) str.substr(starOfRow + col , 1).data();
			if(*colorIndex == 0){
			this->_zero = str.substr(starOfRow + col , 1);
			}
			this->_matrix->setValue(rowIndex, col, *colorIndex);
		}
	}
}

const string& BMArrayWithColorPattle::getStr() const {
	return this->_str;
}

uint32_t BMArrayWithColorPattle::getWidth() const {
	return this->_width;
}

uint32_t BMArrayWithColorPattle::getHeight() const {
	return this->_height;
}

uint16_t BMArrayWithColorPattle::getbytesPeddingPerRow() const {
	return this->_bytesPeddingPerRow;
}

MatrixClass& BMArrayWithColorPattle::getBitMap() const {
	return *(this->_matrix);
}

void BMArrayWithColorPattle::changeToGray() {
	for(uint32_t row = 0; row < this->_height; ++row){
		for (uint32_t col = 0; col < this->_width; ++col) {
			this->_colorTable->changeColorToGray((uint32_t) ((*(this->_matrix))(row, col)));
		}
	}
}

void BMArrayWithColorPattle::rotate() {
		//switching width & height
	uint32_t width = this->_width;
	uint32_t height = this->_height;
	this->_height = width;
	this->_width = height;

	MatrixClass* newMatrix = new MatrixClass(this->_height, this->_width);

	//Itarating on the old matrixes and intalizing the new ones.
	for (uint32_t row = 0; row < this->_width; ++row) {
		for (uint32_t col = 0; col < this->_height; ++col) {
		
			newMatrix->setValue(col, this->_width - row - 1,(*(this->_matrix))(row, col));
		
		}
	}
	delete this->_matrix;

	this->_matrix = newMatrix;

	//writing it to the str:

	for (uint32_t row = 0; row < this->_height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (this->_width + _bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (this->_height - 1) - row;

		uint16_t color;
    	char* c;
   		string s;
		for (uint32_t col = 0; col < this->_width; ++col) {
			if ((*(this->_matrix))(rowIndex, col) != 0) {
				color = (uint16_t) (*(this->_matrix))(rowIndex, col);
				c = (char*) &color;
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->_zero;	
			}
			this->_str.replace(starOfRow + col , 1, s);
		}
	}
}

