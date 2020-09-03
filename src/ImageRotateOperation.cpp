#include "ImageRotateOperation.hpp"

ImageRotateOperation::ImageRotateOperation(const int argc, const char *argv[], bool isSearched /*= false*/) {
    if (!typed(argv[2], "txt") || !typed(argv[3], "txt")) {
        throw runtime_error("Matrix input files must be with type '.txt'.");
    }
    
    //saves the data from the command
    _inputFilesPath.push_back(copyToString(argv[2]));
    _inputFilesPath.push_back(copyToString(argv[3]));
    if (!isSearched) {
        if (typed(argv[4], "txt") || (copyToString(argv[4]).compare(PRINT) == 0)) {
            _outputFilePath = copyToString(argv[4]);
        } else {
            throw runtime_error("Matrix output file must be with type '.txt' or be 'stdout'.");
        }
    }
}

string ImageRotateOperation::getOutputFileType() const { return "bmp"; }

string ImageRotateOperation::getCacheCode() const { return "image_rotate"; }

string ImageRotateOperation::getCacheString() const { 
    return "image_rotate " + to_string(crc32(_inputFilesPath.at(0)));
}

void ImageRotateOperation::writeToFile(const string& fileName) const {
    auto matrix1 = make_unique<MatrixClass>(_inputFilesPath.at(0));
    auto matrix2 = make_unique<MatrixClass>(_inputFilesPath.at(1));

    *matrix1 += *matrix2;

    if (fileName.compare(PRINT) == 0) {
        cout << *matrix1;
    } else {
        writeFileContent(fileName, matrix1->toString());
    }
}