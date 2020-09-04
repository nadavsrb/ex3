#pragma once

#include <cstdint>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::uint32_t;

#define NUM_BYTES_OF_SIZE_AND_OFFSET 4
#define LOCATION_OF_SIZE 2
#define LOCATION_OF_OFFSET 10
class BMPHeaderParser {

//Fields
	string _str;
	uint32_t _size;
	uint32_t  _offset;
public:
	/**
	 * @brief Construct a new BMPHeaderParser object.
	 * 
	 * @param str the string from the BMP file
	 * that refers to header.
	 */
	BMPHeaderParser(const string& str);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return the string from the BMP file
	 * * that refers to header.
	 */
	const string& getStr() const;

	/**
	 * @brief Get the Size object.
	 * 
	 * @return the the size of the BMP file, in bytes.
	 */
	uint32_t getSize() const;

	/**
	 * @brief Get the Offset object.
	 * 
	 * @return the Offset of the pixel array in bytes.
	 */
	uint32_t getOffset() const;
};
