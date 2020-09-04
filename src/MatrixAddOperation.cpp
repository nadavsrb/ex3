#include "MatrixֹAddOperation.hpp"

using namespace OperatorsHelpingFuncs;
using namespace std;

MatrixAddOperation::MatrixAddOperation(const int argc, const char *argv[], bool isSearched /*= false*/){
    int argsExpected = argc;
    if (isSearched) {
        argsExpected++;
    }

    if (argsExpected != 3) {
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

    _cacheString = getCacheCode();
    for (auto file: _inputFilesPath) {
        _cacheString += " ";
        MatrixClass matrix(file);
        _cacheString += std::to_string(crc32FromString(matrix.toString())); //don't see " "
    }
}

string MatrixAddOperation::getOutputFileType() const { return "txt"; }

string MatrixAddOperation::getCacheCode() const { return "matrix_add"; }

string MatrixAddOperation::getCacheString() const { return _cacheString; }

void MatrixAddOperation::writeToFile(const string& fileName) const {
    if(_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }

    auto matrix1 = make_unique<MatrixClass>(_inputFilesPath.at(0));
    auto matrix2 = make_unique<MatrixClass>(_inputFilesPath.at(1));

    *matrix1 += *matrix2;

    if (fileName.compare(PRINT) == 0) {
        cout << *matrix1;
    } else {
        writeFileContent(fileName, matrix1->toString());
    }
}