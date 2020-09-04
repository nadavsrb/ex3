#include "MatrixMultOperation.hpp"

using namespace OperatorsHelpingFuncs;
using namespace std;

MatrixMultOperation::MatrixMultOperation(const int argc, const char *argv[], bool isSearched /*= false*/){
    //fixing the expected args if the operation is from search.
    int argsExpected = argc;
    if (isSearched) {
        argsExpected++;
    }

    //exceptions
    if (argsExpected != 3) { // 2 input files & 1 output file
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    if (!typed(argv[START_INDEX], "txt") || !typed(argv[START_INDEX + 1], "txt")) {
        throw runtime_error("Matrix input files must be with type '.txt'.");
    }
    
    //saves the data from the command
    _inputFilesPath.push_back(copyToString(argv[START_INDEX]));
    _inputFilesPath.push_back(copyToString(argv[START_INDEX + 1]));
    if (!isSearched) { //is it's from searched operation ther isn't output file
        if (typed(argv[START_INDEX + 2], "txt") || (copyToString(argv[START_INDEX + 2]).compare(PRINT) == 0)) {
            _outputFilePath = copyToString(argv[START_INDEX + 2]);
        } else {
            throw runtime_error("Matrix output file must be with type '.txt' or be 'stdout'.");
        }
    }

    //Calculating the _cacheString. At first we would get the matrixes
    //and from them we are getting the string. we do that for macking
    //same matrix with spaces would be equals.
    _cacheString = getCacheCode();
    for (auto file: _inputFilesPath) {
        _cacheString += " ";
        MatrixClass matrix(file);
        _cacheString += to_string(crc32FromString(matrix.toString())); //don't see " "
    }
}
    
string MatrixMultOperation::getOutputFileType() const { return "txt"; }

string MatrixMultOperation::getCacheCode() const { return "matrix_multiply"; }

string MatrixMultOperation::getCacheString() const { return _cacheString; }

void MatrixMultOperation::writeToFile(const string& fileName) const {
    if(_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }

    //creating the matrixes
    auto matrix1 = make_unique<MatrixClass>(_inputFilesPath.at(START_INDEX));
    auto matrix2 = make_unique<MatrixClass>(_inputFilesPath.at(START_INDEX + 1));

    //calculating the operation
    *matrix1 *= *matrix2;

    if (fileName.compare(PRINT) == 0) {//if output file is stdout
        cout << *matrix1;
    } else {
        writeFileContent(fileName, matrix1->toString());
    }
}