#include "BMArrayParserToMatrixes.hpp"

using namespace bmp;

BMArrayParserToMatrixes::BMArrayParserToMatrixes(const string& str, uint32_t width, uint32_t height) {
	this->_str = str;
	this->_width = width;
	this->_height = height;
	this->_Rmatrix = new matrix::MatrixClass(height, width);
	this->_Gmatrix = new matrix::MatrixClass(height, width);
	this->_Bmatrix = new matrix::MatrixClass(height, width);

	//calculating how much padding for width *3 (=nub bits to pixel) to be 4*int
	this->_bytesPeddingPerRow = (4 - ((width * 3) % 4))%4;

	for (uint32_t row = 0; row < height; ++row) {
		//where in the string the new row of the matrix starts
		uint32_t starOfRow = row * (width * 3 + _bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (height - 1) - row;
		for (uint32_t col = 0; col < width; ++col) {
			//startOfRaw in the matrix, col = num of pixel in the raw before (*3 = his size in the string)
			uint16_t* r = (uint16_t*) str.substr(starOfRow + col * 3, 1).data();
			if(*r == 0){
			this->_zero = str.substr(starOfRow + col * 3, 1);
			}

			uint16_t* g = (uint16_t*) str.substr(starOfRow + col * 3 + 1, 1).data();
			if(*r == 0){
			this->_zero = str.substr(starOfRow + col * 3 + 1, 1);
			}

			uint16_t* b = (uint16_t*) str.substr(starOfRow + col * 3 + 2, 1).data();
			if(*r == 0){
			this->_zero = str.substr(starOfRow + col * 3 + 2, 1);
			}

			this->_Rmatrix->setValue(rowIndex, col, *r);
			this->_Gmatrix->setValue(rowIndex, col, *g);
			this->_Bmatrix->setValue(rowIndex, col, *b);
		}
	}
}

const string& BMArrayParserToMatrixes::getStr() {
	//writing the changes to the string
	for (uint32_t row = 0; row < this->_height; ++row) {
		//wher in the string the new row of the matrix starts
		uint32_t starOfRow = row * (this->_width * 3 + _bytesPeddingPerRow);

		//the file is starting from the bottom left of 
		//the picture to the upper right of the picture.
		uint32_t rowIndex = (this->_height - 1) - row;

		uint16_t color;
    	char* c;
   		string s;
		//Note: if we have 0 in one of the var we check
		// it means we got a zero when we read (and intalized _zero)
		//(if the 0 is from changeToGray() it means there were a place were
		//R=0, G=0, B=0
		for (uint32_t col = 0; col < this->_width; ++col) {
			if ((*(this->_Rmatrix))(rowIndex, col) != 0) {
				color = (uint16_t) (*(this->_Rmatrix))(rowIndex, col);
				c = (char*) &color;
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->_zero;	
			}
			this->_str.replace(starOfRow + col * 3, 1, s);

			if ((*(this->_Gmatrix))(rowIndex, col) != 0) {
				color = (uint16_t) (*(this->_Gmatrix))(rowIndex, col);
				c = (char*) &color;
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->_zero;	
			}
			this->_str.replace(starOfRow + col * 3 + 1, 1, s);

			if ((*(this->_Bmatrix))(rowIndex, col) != 0) {
				color = (uint16_t) (*(this->_Bmatrix))(rowIndex, col);
				c = (char*) &color;
   		 		s = c;
			}else{//0 is special to write
   		 		s = this->_zero;	
			}
			this->_str.replace(starOfRow + col * 3 + 2, 1, s);
		}
	}

	return this->_str;
}

uint32_t BMArrayParserToMatrixes::getWidth() const {
	return this->_width;
}

uint32_t BMArrayParserToMatrixes::getHeight() const {
	return this->_height;
}

uint16_t BMArrayParserToMatrixes::getbytesPeddingPerRow() const {
	return this->_bytesPeddingPerRow;
}

matrix::MatrixClass& BMArrayParserToMatrixes::getBitMapR() const {
	return *(this->_Rmatrix);
}

matrix::MatrixClass& BMArrayParserToMatrixes::getBitMapG() const {
    return *(this->_Gmatrix);
}

matrix::MatrixClass& BMArrayParserToMatrixes::getBitMapB() const {
    return *(this->_Bmatrix);
}

void BMArrayParserToMatrixes::changeToGray() {
	*(this->_Rmatrix) *= 0.2126;
	*(this->_Gmatrix) *= 0.7152;
	*(this->_Bmatrix) *= 0.0722;

	matrix::MatrixClass gray(this->_height, this->_width);
	gray += *(this->_Rmatrix);
	gray += *(this->_Gmatrix);
	gray += *(this->_Bmatrix);

	*(this->_Rmatrix) = gray;
	*(this->_Gmatrix) = gray;
	*(this->_Bmatrix) = gray;
}

void BMArrayParserToMatrixes::rotate() {
	//switching width & height
	uint32_t width = this->_width;
	uint32_t height = this->_height;
	this->_height = width;
	this->_width = height;

	matrix::MatrixClass* newRmatrix = new matrix::MatrixClass(this->_height, this->_width);
	matrix::MatrixClass*  newGmatrix = new matrix::MatrixClass(this->_height, this->_width);
	matrix::MatrixClass*  newBmatrix = new matrix::MatrixClass(this->_height, this->_width);

	//Itarating on the old matrixes and intalizing the new ones.
	for (uint32_t row = 0; row < this->_width; ++row) {
		for (uint32_t col = 0; col < this->_height; ++col) {
		
			newRmatrix->setValue(col, this->_width - row - 1,(*(this->_Rmatrix))(row, col));
			newGmatrix->setValue(col, this->_width -  row - 1,(*(this->_Gmatrix))(row, col));
			newBmatrix->setValue(col, this->_width -  row - 1,(*(this->_Bmatrix))(row, col));
		
		}
	}
	delete this->_Rmatrix;
	delete this->_Gmatrix;
	delete this->_Bmatrix;

	this->_Rmatrix = newRmatrix;
	this->_Gmatrix = newGmatrix;
	this->_Bmatrix = newBmatrix;
}
