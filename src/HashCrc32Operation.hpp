#pragma once

#include "Operation.hpp"

class HashCrc32Operation : public Operation {
public:
    HashCrc32Operation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const override;
    string getCacheCode() const override;
    string getCacheString() const override;

    void writeToFile(const string& fileName) const override;
};