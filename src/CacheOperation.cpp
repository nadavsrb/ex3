#include "CacheOperation.hpp"
#include "CacheManager.hpp"

#define PRINT "stdout"

string copyToString(const char *charArray) {
    string str = "";
    for (unsigned int i = 0; charArray[i] != '\0'; ++i) {
        str += charArray[i];
    }

    return str;
}

CacheOperation::CacheOperation(const int argc, const char *argv[], bool isSearched /*= false*/) {
    int argsExpected = argc;
    if (isSearched) {
        argsExpected++;
    }

    if (argc < 1) {
        cerr << "Invalid input! Too few arguments." << endl;
    } else if (argc == 1) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    } else if (strcmp(argv[0], "matrix") == 0) {
        if (argsExpected != 5) {
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

        if (!isSearched) {
            _outputFilePath = copyToString(argv[4]);
        }
    } else if (strcmp(argv[0], "image") == 0) {
        if (argsExpected != 4) {
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

        if (!isSearched) {
            _outputFilePath = copyToString(argv[3]);
        }
    } else if (strcmp(argv[0], "hash") == 0) {
        if (argsExpected != 4) {
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

        if (!isSearched) {
            _outputFilePath = copyToString(argv[3]);
        }

    } else if (strcmp(argv[0], "cache") == 0) {
        if (strcmp(argv[1], "search") == 0) {
            _cacheCode = SEARCH;
            _itemSearched = make_shared<CacheOperation>(argc - 2, &argv[2], true);
        } else if (strcmp(argv[1], "clear") == 0) {
            _cacheCode = CLEAR;
        } else {
            throw UNKNOWN_COMMAND;
        }
    } else {
        throw UNKNOWN_COMMAND;
    }


    //adding the method
    _cacheString += std::to_string(_cacheCode);
    if (_cacheCode == SEARCH) {
         _cacheString += " ";
         _cacheString += _itemSearched->getCacheString();
         //delete the operation searche date & time & \n & " "
         _cacheString.erase(_cacheString.length() - CurrentTime::TIME_STRING_LENGTH - 2, CurrentTime::TIME_STRING_LENGTH + 2);
    } else if (_cacheCode != CLEAR) {
        //adding the input files path
        if (_cacheCode == MATRIX_MULT || _cacheCode == MATRIX_ADD) {
            for (vector<string>::iterator it = _inputFilesPath.begin(); it < _inputFilesPath.end(); ++it) {
                _cacheString += " ";
                MatrixClass matrix(*it);
                _cacheString += std::to_string(crc32FromString(matrix.toString())); //don't see " "
            }
        } else {
            for (vector<string>::iterator it = _inputFilesPath.begin(); it < _inputFilesPath.end(); ++it) {
                _cacheString += " ";
                _cacheString += std::to_string(crc32(*it));
            }
        }
    }

    //adding the time & date
    _cacheString += ",";
    CurrentTime ct = CurrentTime();
    _cacheString += ct.getTime();
}

bool CacheOperation::isClear() const {
    return _cacheCode == CLEAR;
}

bool CacheOperation::isSearch() const {
    return _cacheCode == SEARCH;
}


string CacheOperation::getCacheString() const {
    return _cacheString;
}

string CacheOperation::getOutputFileType() const {
    if(_outputFilePath == "stdout") {
        return "text";
    }
    return _outputFilePath.substr(_outputFilePath.find_last_of('.') + 1, _outputFilePath.size() - 1);
}


void CacheOperation::writeToOutputFile() const {
    writeToFile(_outputFilePath);
}

void CacheOperation::writeToFile(const string& fileName) const {
    if (_cacheCode == MATRIX_MULT || _cacheCode == MATRIX_ADD) {
        auto m1 = make_unique<MatrixClass>(_inputFilesPath.at(0));
        auto m2 = make_unique<MatrixClass>(_inputFilesPath.at(1));

        if (_cacheCode == MATRIX_MULT) {
            *m1 *= *m2;
        } else {
            *m1 += *m2;
        }

        if (fileName.compare(PRINT) == 0) {
            cout << *m1;
        } else {
            writeFileContent(fileName, m1->toString());
        }
    } else if (_cacheCode == IMAGE_CONVERT) {
        testing::bmp::convert_to_grayscale(_inputFilesPath.at(0), fileName);
    } else if (_cacheCode == IMAGE_ROTATE) {
        testing::bmp::rotate_image(_inputFilesPath.at(0), fileName);
    } else if (_cacheCode == HASH_CRC32) {
        string result = "";
        result += std::to_string(crc32(_inputFilesPath.at(0)));

        if (fileName.compare(PRINT)  == 0) {
            cout << result << endl;
        } else {
            writeFileContent(fileName, result);
        }
    } else if (_cacheCode == SEARCH) {
        string search = CacheManager::search(_itemSearched);
        if(search == "") {
             cout << "result wasn't found in cache" << endl;
        } else {
            cout << "result found in cache – saved on " << search.substr(0, CurrentTime::TIME_STRING_LENGTH) << endl;
        }
    }

    // note that the CLEAR operation is performed in the CachManager module
}
