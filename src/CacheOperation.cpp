#include "CacheOperation.hpp"

string copyToString(const char *charArray) {
    string str = "";
    for (unsigned int i = 0; charArray[i] != '\0'; ++i) {
        str += charArray[i];
    }

    return str;
}

CacheOperation::CacheOperation(const int argc, const char *argv[]) {
    if (argc < 1) {
        cerr << "Invalid input! Too few arguments." << endl;
    } else if (argc == 1) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    } else if (strcmp(argv[0], "matrix") == 0) {
        if (argc != 5) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }

        //getting the operation to do on the matrix
        if (strcmp(argv[1], "multiply") == 0) {
            _cacheCode = MATRIX_MULT;
        } else if (strcmp(argv[1], "add") == 0) {
            _cacheCode = MATRIX_ADD;
        } else {
            throw UNKNOWN_COMMAND;
        }
        
        //saves the data from the command
        _inputFilesPath.push_back(copyToString(argv[2]));
        _inputFilesPath.push_back(copyToString(argv[3]));
        _outputFilePath = copyToString(argv[4]);
    } else if (strcmp(argv[0], "image") == 0) {
        if (argc != 4) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }
        
        //getting the operation to do on the image
        if (strcmp(argv[1], "rotate") == 0) {
            _cacheCode = IMAGE_ROTATE;
        } else if (strcmp(argv[1], "convert") == 0) {
            _cacheCode = IMAGE_CONVERT;
        } else {
            throw UNKNOWN_COMMAND;
        }

        //saves the data from the command
        _inputFilesPath.push_back(copyToString(argv[2]));
        _outputFilePath = copyToString(argv[3]);
    } else if (strcmp(argv[0], "hash") == 0) {
        if (argc != 4) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }
        
        //getting the hash algoritem to do
        if (strcmp(argv[1], "crc32") == 0) {
            _cacheCode = HASH_CRC32;
        } else {
            throw UNKNOWN_COMMAND;
        }

        //saves the data from the command
        _inputFilesPath.push_back(copyToString(argv[2]));
        _outputFilePath = copyToString(argv[3]);

    } else if (strcmp(argv[0], "cache") == 0) {
        if (strcmp(argv[1], "search") == 0) {
            _cacheCode = SEARCH;
            //_itemSearched = make_shared<CacheOperation>(argc - 1, argv + 1);
        }else if (strcmp(argv[1], "clear") == 0) {
            _cacheCode = CLEAR;
        } else {
            throw UNKNOWN_COMMAND;
        }
    } else {
        throw UNKNOWN_COMMAND;
    }

    //adding the time & date
    CurrentTime ct = CurrentTime();
    _cacheString += ct.getTime();
    _cacheString+= " ";

    //adding the method
    _cacheString += _cacheCode;
    if (_cacheCode == SEARCH) {
         _cacheString+= " ";
         //_cacheString += _itemSearched->getCacheString();
    } else if(_cacheCode != CLEAR){//not a cashe method

        //adding the input files path
        for (vector<string>::iterator it = _inputFilesPath.begin(); it < _inputFilesPath.end(); ++it) {
            _cacheString+= " ";
            _cacheString += *it;
        }

        //adding the output file path
            _cacheString+= " ";
            _cacheString+= _outputFilePath;
    }
}

string CacheOperation::getCacheString() const {
    return _cacheString;
}
