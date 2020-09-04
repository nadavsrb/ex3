#include "ImageRotateOperation.hpp"

ImageRotateOperation::ImageRotateOperation(const int argc, const char *argv[], bool isSearched /*= false*/) {
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

string ImageRotateOperation::getOutputFileType() const { return "bmp"; }

string ImageRotateOperation::getCacheCode() const { return "image_rotate"; }

string ImageRotateOperation::getCacheString() const { return _cacheString; }

void ImageRotateOperation::writeToFile(const string& fileName) const {
    testing::bmp::rotate_image(_inputFilesPath.at(0), fileName);
}