#include "HashCrc32Operation.hpp"

using namespace cache::operatorsHelpingFuncs;
using namespace std;
using namespace cache::operation;

    HashCrc32Operation::HashCrc32Operation(const int argc, const char *argv[], bool isSearched /*= false*/){
        //fixing the expected args if the operation is from search.
        int argsExpected = argc;
        if (isSearched) {
            argsExpected++;
        }

        //exceptions
        if (argsExpected != 2) {//1 input file & 1 output file
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }

        //if not searched operatin intalize the output file.
        _inputFilesPath.push_back(copyToString(argv[START_INDEX]));

        if (!isSearched) {
            _outputFilePath = copyToString(argv[START_INDEX + 1]);
            if(_outputFilePath.find('.') == std::string::npos && _outputFilePath.compare("stdout") != 0) {
                throw runtime_error("Output file must have a type or be 'stdout'.");
            }
        }
    
         //Calculating the _cacheString.
        _cacheString = getCacheCode() + " " + std::to_string(crc32::crc32(_inputFilesPath.at(START_INDEX)));
    }
    
    string HashCrc32Operation::getOutputFileType() const { return "txt"; }

    string HashCrc32Operation::getCacheCode() const { return "hash_crc32"; }

    string HashCrc32Operation::getCacheString() const { return _cacheString; }

    void HashCrc32Operation::writeToFile(const string& fileName) const {
        if(_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
            return;
        }
        string result = "";
        result += std::to_string(crc32::crc32(_inputFilesPath.at(START_INDEX)));

        if (fileName.compare(PRINT)  == 0) {
            cout << result << endl;
        } else {
            files::writeFileContent(fileName, result);
        }
    }