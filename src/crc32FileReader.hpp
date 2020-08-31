#pragma once

#include <string.h>
#include <string>
#include "crc32.hpp"
#include "file_reading.hpp"
#include <algorithm>

using std::uint32_t;
using std::string;

/**
 * @brief Performs the crc32 algorithem.
 * 
 * @param filePath - the input bit array is in the file.
 * @return uint32_t 
 */
uint32_t crc32(const string& filePath);
/**
 * @brief Performs the crc32 algorithem.
 * 
 * @param s - the input in string
 * @return uint32_t 
 */
uint32_t crc32FromString(const string& file);
