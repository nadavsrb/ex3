#pragma once

#include <cstdint>

using std::uint16_t;
class Color {

	uint16_t _R;
	uint16_t _G;
	uint16_t _B;

public:
	Color(uint16_t R, uint16_t G, uint16_t B);

	/**
	 * @brief Returns the R value in the rgb of the color.
	 * 
	 * @return uint16_t the R value in the rgb of the color.
	 */
	uint16_t getR() const;

	/**
	 * @brief Returns the G value in the rgb of the color.
	 * 
	 * @return uint16_t the G value in the rgb of the color.
	 */
	uint16_t getG() const;

	/**
	 * @brief Returns the B value in the rgb of the color.
	 * 
	 * @return uint16_t the B value in the rgb of the color.
	 */
	uint16_t getB() const;

	/**
	 * @brief Turn this color to gray Color.
	 * 
	 */
	void toGray();
};
