#pragma once

#include <string>
#include <memory>

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
    string _filesArray[3];
    weak_ptr<CacheOperation> _itemSearched;
};