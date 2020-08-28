#pragma once

#include <fstream>
#include <string>

using std::uint32_t;
using std::string;

/**
 * @brief Performs the crc32 algorithem.
 * 
 * @param filePath - the input bit array is in the file.
 * @return uint32_t 
 */
uint32_t crc32(const string& filePath);
