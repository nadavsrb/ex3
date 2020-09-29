#include "StringFunctions.hpp"

using std::string;

bool cache::operatorsHelpingFuncs::typed(const string& fileName, const string& type) {
    return fileName.substr(fileName.find_last_of('.') + 1).compare(type) == 0;
}