#pragma once

#include "crc32FileReader.hpp"
#include "Operation.hpp"

class HashCrc32Operation : public Operation {
public:
    HashCrc32Operation(const int argc, const char *argv[], bool isSearched = false);
    
    std::string getOutputFileType() const override;
    std::string getCacheCode() const override;
    std::string getCacheString() const override;

    void writeToFile(const std::string& fileName) const override;
};