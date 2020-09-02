#pragma once

#include <fstream>
#include <iterator>
#include <string>
#include <system_error>
#include <errno.h>

std::string readFileContent(const std::string& filePath);

void writeFileContent(const std::string& filePath, const std::string& content);