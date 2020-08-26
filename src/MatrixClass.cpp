#include "MatrixClass.hpp"

//Implementing methods
	MatrixClass::MatrixClass(uint32_t height, uint32_t width){
        //creating the matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_create(&_matrix, height, width));
    }

    MatrixClass::MatrixClass(const MatrixClass& source){
        //copy the matrix & throwing excepstion if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&_matrix, source._matrix));
    }

    MatrixClass& MatrixClass::operator=(const MatrixClass& source){

        //Trying to destroy the matrix in the field (if not intalized yet would do nothing)
        matrix_destroy(_matrix);

        //creating copy of the matrix in the field & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_copy(&_matrix, source._matrix));

        return *this;
    }

    uint32_t MatrixClass::getHeight() const {
        uint32_t height;

        //gets the height & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getHeight(_matrix, &height));

        return height;
    }

    uint32_t MatrixClass::getWidth() const {
        uint32_t width;

        //gets the width & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(matrix_getWidth(_matrix, &width));

        return width;
    }

    void MatrixClass::setValue(uint32_t rowIndex, uint32_t colIndex,
                           double value) {
        //sets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_setValue(_matrix, rowIndex, colIndex, value));
    }

    double MatrixClass::operator()(uint32_t rowIndex, uint32_t colIndex) const{
        double value;

        //gets the value & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_getValue(_matrix, rowIndex, colIndex, &value));

        return value;
    }

    MatrixClass& MatrixClass::operator+=(const MatrixClass& other) {
        //Creating the result matrix 
        PMatrix result;
        matrix_create(&result, this->getHeight(), this->getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_add(&result, _matrix, other._matrix));

        //destroying the corrent matrix
        matrix_destroy(_matrix);

        //updating the matrix to the result
        _matrix = result;

        return *this;
    }

    MatrixClass&  MatrixClass::operator-=(const MatrixClass& other) {
        MatrixClass* minusOther = &(other * (-1));
        (*this) += *minusOther;
        delete minusOther;
        return *this;
    }

    MatrixClass& MatrixClass::operator*=(const MatrixClass& other) {
        //Creating the result matrix 
        PMatrix result;
        matrix_create(&result, this->getHeight(), other.getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyMatrices(&result, _matrix, other._matrix));

        //destroying the corrent matrix
        matrix_destroy(_matrix);

        //updating the matrix to the result
        _matrix = result;

        return *this;
    }

    MatrixClass& MatrixClass::operator*=(double scalar){
        //Multipling this matrix with the scalar into 
        //this matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyWithScalar(_matrix, scalar));

        return *this;
    }

    MatrixClass& MatrixClass::operator/=(double scalar) {
        return *(this) *= (1 / scalar);
    }

    MatrixClass::~MatrixClass() {
        //destroying the corrent matrix
        matrix_destroy(_matrix);
    }

//another operators. warning! they return new MatrixClass
    MatrixClass& MatrixClass::operator+(const MatrixClass& other) const{
        //Creating the result matrix 
        MatrixClass* result = new MatrixClass(this->getHeight(), this->getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_add(&result->_matrix, _matrix, other._matrix));

        return *result;
    }

    MatrixClass& MatrixClass::operator-(const MatrixClass& other) const {
        MatrixClass* minusOther = &(other * (-1));
        MatrixClass* result = &((*this) + *minusOther);
        delete minusOther;
        return *result;
    }

    MatrixClass& MatrixClass::operator*(const MatrixClass& other) const{
        //Creating the result matrix 
        MatrixClass* result = new MatrixClass(this->getHeight(), other.getWidth());

        //Calculating result matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyMatrices(&result->_matrix, _matrix, other._matrix));

        return *result;
    }

    MatrixClass& MatrixClass::operator*(double scalar) const {
        //Creating the result matrix (copying this matrix)
        MatrixClass* result = new MatrixClass(*this);

        //Multipling this matrix with the scalar into 
        //this matrix & throwing exception if needed
        ErrorCodeException::throwErrorIfNeeded(
            matrix_multiplyWithScalar(result->_matrix, scalar));

        return *result;
    }

    MatrixClass& MatrixClass::operator/(double scalar) const {
        return *this * (1 / scalar);
    }

//friends functins
    std::ostream& operator<<(std::ostream& stream, const MatrixClass& matrix){
        //var to use
        uint32_t height = matrix.getHeight();
        uint32_t width = matrix.getHeight();

        for(uint32_t row = 0; row < height; ++row) {
            for(uint32_t col = 0; col < width; ++col) {
                stream<<matrix(row, col)<<"|";
                }

        stream<<endl;
        }

        return stream;
    }

    MatrixClass& operator*(double scalar, const MatrixClass& matrix) {
        return matrix * scalar;
    }
