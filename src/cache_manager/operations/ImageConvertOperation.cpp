#include "ImageConvertOperation.hpp"

using namespace cache::operatorsHelpingFuncs;
using namespace std;
using namespace cache::operation;

ImageConvertOperation::ImageConvertOperation(const int argc, const char *argv[], bool isSearched /*= false*/){
    //fixing the expected args if the operation is from search.
    int argsExpected = argc;
    if (isSearched) {
        argsExpected++;
    }

    //exceptions
    if (argsExpected != 2) {// 1 input file & 1 output file
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    if (!typed(argv[START_INDEX], "bmp")) {
        throw runtime_error("Image files must be with type '.bmp'.");
    }

    //saves the data from the command
    _inputFilesPath.push_back(copyToString(argv[START_INDEX]));

    //if not searched operatin intalize the output file.
    if (!isSearched) {
        if (typed(argv[START_INDEX], "bmp")) {
            _outputFilePath = copyToString(argv[START_INDEX + 1]);
        } else {
            throw runtime_error("Image files must be with type '.bmp'.");
        }
    }

     //Calculating the _cacheString.
    _cacheString = getCacheCode() + " " + to_string(crc32::crc32(_inputFilesPath.at(START_INDEX)));
}

string ImageConvertOperation::getOutputFileType() const { return "bmp"; }

string ImageConvertOperation::getCacheCode() const { return "image_convert"; }

string ImageConvertOperation::getCacheString() const { return _cacheString; }

void ImageConvertOperation::writeToFile(const string& fileName) const {
    if(_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }
    testing::bmp::convert_to_grayscale(_inputFilesPath.at(START_INDEX), fileName);
}