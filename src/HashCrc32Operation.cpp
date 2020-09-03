#include "HashCrc32Operation.hpp"


    HashCrc32Operation::HashCrc32Operation(const int argc, const char *argv[], bool isSearched /*= false*/) {
        int argsExpected = argc;
        if (isSearched) {
            argsExpected++;
        }

        if (argsExpected != 2) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }

        //saves the data from the command
        _inputFilesPath.push_back(copyToString(argv[0]));

        if (!isSearched) {
            _outputFilePath = copyToString(argv[1]);
            if(_outputFilePath.find('.') == std::string::npos && _outputFilePath.compare("stdout") != 0) {
                throw runtime_error("Output file must have a type or be 'stdout'.");
            }
        }
    
        _cacheString = getCacheCode();
        for (auto file: _inputFilesPath) {
             _cacheString += " ";
             _cacheString += std::to_string(crc32(file));
        }
    }
    
    string HashCrc32Operation::getOutputFileType(){
        return "txt";
    }

    string HashCrc32Operation::getCacheCode(){
        return "hash_crc32";
    }

    void HashCrc32Operation::writeToOutputFile() {

    }

    void HashCrc32Operation::writeToOutputFile(const string& content) {

    }
    
    void HashCrc32Operation::writeToFile(const string& fileName);