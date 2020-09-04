#pragma once

#include "Color.hpp"

#include <cstdint>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::uint32_t;
using std::uint16_t;

class ColorTableParser {

	string _str;
	vector<Color*> _colors;

public:
	/**
	 * @brief Construct a new Color Table Parser object.
	 * 
	 * @param str the string from the BMP file
	 *  that refers to Color Palette.
	 */
	ColorTableParser(const string& str);

	/**
	 * @brief Get the Str object.
	 * 
	 * @return const string& the string from the BMP file
	 *  that refers to Color Palette.
	 */
	const string& getStr() const;

	/**
	 * @brief Get the Color Count object.
	 * 
	 * @return uint32_t the size of the Color Palette
	 *  (num of colors).
	 */
	uint32_t getColorCount() const;

	/**
	 * @brief Get the Color object.
	 * 
	 * @param n 
	 * @return Color the color in the n location.
	 */
	Color getColor(uint32_t n) const;

	/**
	 * @brief Get the Colors object.
	 * 
	 * @return vector<Color> the vector that represents the
	 * Color Palette.
	 */
	vector<Color*> getColors() const;

	/**
	 * @brief changing the specific color to gray.
	 * 
	 * @param n the index of the color in the vector<Color>. 
	 */
	void changeColorToGray(uint32_t n);

	/**
	 * @brief Destroy the Color Table Parser object
	 * 
	 */
	~ColorTableParser();
};
