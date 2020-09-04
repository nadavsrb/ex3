#pragma once

#include "crc32FileReader.hpp"
#include "Operation.hpp"
#include "MatrixClass.hpp"

#include <memory>

class MatrixAddOperation : public Operation {
public:
    MatrixAddOperation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const override;
    string getCacheCode() const override;
    string getCacheString() const override;

    void writeToFile(const string& fileName) const override;
};