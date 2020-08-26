#pragma once

#include <fstream>
#include <iterator>
#include <string>

std::string readFileContent(const std::string& filePath);

void writeFileContent(const std::string& filePath, const std::string& content);