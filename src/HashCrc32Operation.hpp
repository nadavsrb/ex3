#pragma once

#include "Operation.hpp"

class HashCrc32Operation : public Operation {
public:
    HashCrc32Operation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const;
    string getCacheCode() const;
    string getCacheString() const;

    void writeToFile(const string& fileName) const;
};