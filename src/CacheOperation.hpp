#pragma once

#include <string>
#include <memory>
#include <string.h>
#include <iostream>

#define NUMBER_OF_ARGUMENTS_ERROR runtime_error("Invalid input! Number of arguments does not suit to the chosen operation.")
#define UNKNOWN_COMMAND runtime_error("Invalid input! Unknown command.")

using namespace std;

typedef enum {
    MATRIX_MULT,
    MATRIX_ADD,
    IMAGE_ROTATE,
    IMAGE_CONVERT,
    HASH_CRC32,
    CLEAR,
    SEARCH
} CacheOperationCode;

class CacheOperation {
public:
    CacheOperation(const int argc, const char *argv[]);

    string getCacheString() const;

private:
    CacheOperationCode _cacheCode;
    string _cacheString;
    string _filesArray[3];
    weak_ptr<CacheOperation> _itemSearched;
};