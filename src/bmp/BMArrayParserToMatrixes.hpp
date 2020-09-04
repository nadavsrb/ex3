#pragma once

#include "MatrixClass.hpp"
#include <cstdint>
#include <string>

using std::uint16_t;
using std::uint32_t;
using std::string;
//for 24 bits pixels
class BMArrayParserToMatrixes {
	//if we read a string that 
	//represent 0 we will save her (writing 0 is special).
	string _zero;

	string _str;
	uint32_t _width;
	uint32_t _height;
	uint16_t _bytesPeddingPerRow; //max 3
	MatrixClass* _Rmatrix;
	MatrixClass* _Bmatrix;
	MatrixClass* _Gmatrix;

public:
	/**
	 * @brief Construct a new BMArrayParserToMatrixes object.
	 * 
	 * @param str 
	 * @param width 
	 * @param height 
	 */
	BMArrayParserToMatrixes(const string& str, uint32_t width, uint32_t height);

	/**
	 * @brief Get the Str object.
	 * (& changing the str to support the matrixes)
	 * 
	 * @return const string& 
	 */
	const string& getStr();

	/**
	 * @brief Get the Width object.
	 * 
	 * @return uint32_t the width of the BitmapArray.
	 */
	uint32_t getWidth() const;
	
	/**
	 * @brief Get the Height object.
	 * 
	 * @return uint32_t the height of the BitmapArray.
	 */
	uint32_t getHeight() const;

	/**
	 * @brief Returns the nummber of bytes pedding per row..
	 * 
	 * @return uint16_t the nummber of bytes pedding per row.
	 */
	uint16_t getbytesPeddingPerRow() const;

	/**
	 * @brief Get the Bit Map R object.
	 * 
	 * @return MatrixClass& the R pixel'S value -matrix of the BitmapArray.
	 */
	MatrixClass& getBitMapR() const;

	/**
	 * @brief Get the Bit Map G object.
	 * 
	 * @return MatrixClass& the G pixel'S value -matrix of the BitmapArray.
	 */
	MatrixClass& getBitMapG() const;

	/**
	 * @brief Get the Bit Map B object.
	 * 
	 * @return MatrixClass& the B pixel'S value -matrix of the BitmapArray.
	 */
	MatrixClass& getBitMapB() const;

	/**
	 * @brief Changes the matrixes to have
	 * together the RGB of the a gray color.
	 * 
	 */
	void changeToGray();

	/**
 	* @brief Rotating the matrixes 90 degree. 
 	* 
 	*/
	void rotate();
};
