#pragma once

#include <string>
#include <memory>
#include <vector>
#include <string.h>
#include <iostream>
#include "CurrentTime.hpp"
#include "MatrixClass.hpp"
#include "file_reading.hpp"
#include "bmp_tester.hpp"
#include "crc32FileReader.hpp"

#define NUMBER_OF_ARGUMENTS_ERROR runtime_error("Invalid input! Number of arguments does not suit to the chosen operation.")
#define UNKNOWN_COMMAND runtime_error("Invalid input! Unknown command.")

using namespace std;

typedef enum {
    MATRIX_MULT = 0,
    MATRIX_ADD = 1,
    IMAGE_ROTATE = 2,
    IMAGE_CONVERT = 3,
    HASH_CRC32 = 4,
    CLEAR = 5,
    SEARCH = 6
} CacheOperationCode;

class CacheOperation {
public:
    CacheOperation(const int argc, const char *argv[], bool isSearched);
    CacheOperation(const int argc, const char *argv[]);

    bool isClear() const;
    bool isSearch() const;
    
    string getCacheString() const;
    string getOutputFileType() const;

    void writeToOutputFile() const; //if the methode isn't a cache methode
    void writeToFile(const string& fileName) const;

private:
    CacheOperationCode _cacheCode;
    string _cacheString = "";
    vector<string> _inputFilesPath;
    string _outputFilePath = "";
    shared_ptr<CacheOperation> _itemSearched; //for search method
};
