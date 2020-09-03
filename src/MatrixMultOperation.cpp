#include "MatrixֹMultOperation.hpp"

MatrixMultOperation::MatrixMultOperation(const int argc, const char *argv[], bool isSearched /*= false*/) {
    if (argc != 3) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    if (!typed(argv[0], "txt") || !typed(argv[1], "txt")) {
        throw runtime_error("Matrix input files must be with type '.txt'.");
    }
    
    //saves the data from the command
    _inputFilesPath.push_back(copyToString(argv[0]));
    _inputFilesPath.push_back(copyToString(argv[1]));
    if (!isSearched) {
        if (typed(argv[2], "txt") || (copyToString(argv[2]).compare(PRINT) == 0)) {
            _outputFilePath = copyToString(argv[2]);
        } else {
            throw runtime_error("Matrix output file must be with type '.txt' or be 'stdout'.");
        }
    }
}
    
string MatrixMultOperation::getOutputFileType() const { return "txt"; }

string MatrixMultOperation::getCacheCode() const { return "matrix multiply"; }

string MatrixMultOperation::getCacheString() const { 
    return "matrix_multiply " + to_string(crc32(_inputFilesPath.at(0))) + " " + to_string(crc32(_inputFilesPath.at(1)));
}

void MatrixMultOperation::writeToOutputFile() const {writeToFile(_outputFilePath); }

void MatrixMultOperation::writeToOutputFile(const string& content) const {
    if (!_outputFilePath.compare(PRINT)) {
        cout << content << endl;
    } else {
        writeFileContent(_outputFilePath, content);
    }
}

void MatrixMultOperation::writeToFile(const string& fileName) const {
    auto matrix1 = make_unique<MatrixClass>(_inputFilesPath.at(0));
    auto matrix2 = make_unique<MatrixClass>(_inputFilesPath.at(1));

    *matrix1 *= *matrix2;

    if (fileName.compare(PRINT) == 0) {
        cout << *matrix1;
    } else {
        writeFileContent(fileName, matrix1->toString());
    }
}