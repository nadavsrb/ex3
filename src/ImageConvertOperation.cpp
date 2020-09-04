#include "ImageConvertOperation.hpp"

using namespace OperatorsHelpingFuncs;
using namespace std;

ImageConvertOperation::ImageConvertOperation(const int argc, const char *argv[], bool isSearched /*= false*/){
    int argsExpected = argc;
    if (isSearched) {
        argsExpected++;
    }

    if (argsExpected != 2) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    if (!typed(argv[0], "bmp")) {
        throw runtime_error("Image files must be with type '.bmp'.");
    }

    //saves the data from the command
    _inputFilesPath.push_back(copyToString(argv[0]));

    if (!isSearched) {
        if (typed(argv[1], "bmp")) {
            _outputFilePath = copyToString(argv[1]);
        } else {
            throw runtime_error("Image files must be with type '.bmp'.");
        }
    }

    _cacheString = getCacheCode() + " " + to_string(crc32(_inputFilesPath.at(0)));
}

string ImageConvertOperation::getOutputFileType() const { return "bmp"; }

string ImageConvertOperation::getCacheCode() const { return "image_convert"; }

string ImageConvertOperation::getCacheString() const { return _cacheString; }

void ImageConvertOperation::writeToFile(const string& fileName) const {
    testing::bmp::convert_to_grayscale(_inputFilesPath.at(0), fileName);
}