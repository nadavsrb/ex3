#include "CacheOperation.hpp"
#include <string.h>
#include <iostream>

#define NUMBER_OF_ARGUMENTS_ERROR runtime_error("Invalid input! Number of arguments does not suit to the chosen operation.")
#define UNKNOWN_COMMAND runtime_error("Invalid input! Unknown command.")

using namespace std;

void copyToString(string& str, const char *charArray) {
    str = "";
    for (unsigned int i = 0; charArray[i] != '\0'; ++i) {
        str += charArray[i];
    }
}

CacheOperation::CacheOperation(const int argc, const char *argv[]) {
    if (argc < 1) {
        cerr << "Invalid input! Too few arguments." << endl;
    } else if (argv[0] == "clear") {
       _cacheCode = CLEAR;
    } else if (argc == 1) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    } else if (argv[0] == "matrix") {
        if (argc != 5) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        } else if (argv[1] == "multiply") {
            _cacheCode = MATRIX_MULT;
            copyToString(_filesArray[0], argv[2]);
            copyToString(_filesArray[1], argv[3]);
            copyToString(_filesArray[2], argv[4]);
        } else if (argv[1] == "add") {
            _cacheCode = MATRIX_ADD;
            copyToString(_filesArray[0], argv[2]);
            copyToString(_filesArray[1], argv[3]);
            copyToString(_filesArray[2], argv[4]);
        } else {
            throw UNKNOWN_COMMAND;
        }
    } else if (argv[0] == "image") {
        if (argc != 4) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        } else if (argv[1] == "rotate") {
            _cacheCode = IMAGE_ROTATE;
            copyToString(_filesArray[0], argv[2]);
            copyToString(_filesArray[1], argv[3]);
        } else if (argv[1] == "convert") {
            _cacheCode = IMAGE_CONVERT;
            copyToString(_filesArray[0], argv[2]);
            copyToString(_filesArray[1], argv[3]);
        } else {
            throw UNKNOWN_COMMAND;
        }
    } else if (argv[0] == "hash") {
        if (argc != 4) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        } else if (argv[1] == "crc32") {
            _cacheCode = HASH_CRC32;
            copyToString(_filesArray[0], argv[2]);
            copyToString(_filesArray[1], argv[3]);
        } else {
            throw UNKNOWN_COMMAND;
        }
    } else if (argv[0] == "cache") {
        if (argv[1] == "search") {
            _cacheCode = SEARCH;
            _itemSearched = make_shared<CacheOperation>(argc - 1, argv + 1);
        } else {
            throw UNKNOWN_COMMAND;
        }
    } else {
        throw UNKNOWN_COMMAND;
    }
    _cacheString = "";
    _cacheString += _cacheCode;
    if (_cacheCode != SEARCH) {
        _cacheString += _filesArray[0] + _filesArray[1] + _filesArray[2];
    } else {
        _cacheString += _itemSearched->getCacheString;
    }
}

string CacheOperation::getCacheString() const {
    return _cacheString;
}
