#pragma once

#include "Operation.hpp"
#include "bmp_tester.hpp"

class ImageConvertOperation : public Operation {
public:
    ImageConvertOperation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const override;
    string getCacheCode() const override;
    string getCacheString() const override;

    void writeToFile(const string& fileName) const override;
};