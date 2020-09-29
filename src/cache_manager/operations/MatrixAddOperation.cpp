#include "MatrixAddOperation.hpp"

using namespace cache::operatorsHelpingFuncs;
using namespace cache::operation;

MatrixAddOperation::MatrixAddOperation(const int argc, const char *argv[], bool isSearched /*= false*/){
    //fixing the expected args if the operation is from search.
    int argsExpected = argc;
    if (isSearched) {
        ++argsExpected;
    }

   //exceptions
    if (argsExpected != 3) {// 2 input files & 1 output file
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    if (!typed(argv[START_INDEX], "txt") || !typed(argv[START_INDEX + 1], "txt")) {
        throw std::runtime_error("Matrix input files must be with type '.txt'.");
    }
    
    //saves the data from the command
    m_inputFilesPath.push_back(copyToString(argv[START_INDEX]));
    m_inputFilesPath.push_back(copyToString(argv[START_INDEX + 1]));
    if (!isSearched) {//is it's from searched operation ther isn't output file
        if (typed(argv[START_INDEX + 2], "txt") || (copyToString(argv[START_INDEX + 2]).compare(PRINT) == 0)) {
            m_outputFilePath = copyToString(argv[START_INDEX + 2]);
        } else {
            throw std::runtime_error("Matrix output file must be with type '.txt' or be 'stdout'.");
        }
    }

    //Calculating the _cacheString. At first we would get the matrixes
    //and from them we are getting the string. we do that for macking
    //same matrix with spaces would be equals.
    m_cacheString = getCacheCode();
    for (auto file: m_inputFilesPath) {
        m_cacheString += " ";
        matrix::MatrixClass matrix(file);
        m_cacheString += std::to_string(crc32::crc32FromString(matrix.toString())); //don't see " "
    }
}

string MatrixAddOperation::getOutputFileType() const { return "txt"; }

string MatrixAddOperation::getCacheCode() const { return "matrix_add"; }

string MatrixAddOperation::getCacheString() const { return m_cacheString; }

void MatrixAddOperation::writeToFile(const string& fileName) const {
    if(m_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }

    //creating the matrixes
    auto matrix1 = std::make_unique<matrix::MatrixClass>(m_inputFilesPath.at(START_INDEX));
    auto matrix2 = std::make_unique<matrix::MatrixClass>(m_inputFilesPath.at(START_INDEX + 1));

    //calculating the operation
    *matrix1 += *matrix2;

    if (fileName.compare(PRINT) == 0) {//if output file is stdout
        std::cout << *matrix1;
    } else {
        files::writeFileContent(fileName, matrix1->toString());
    }
}