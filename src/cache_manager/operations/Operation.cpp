#include "Operation.hpp"


using namespace cache::operation;

Operation::Operation(const Operation& op) {
    _cacheString = op._cacheString;
    _inputFilesPath = op._inputFilesPath;
    _outputFilePath = op._outputFilePath;
 }

Operation::Operation(Operation&& op) : m_cacheString(op.m_cacheString),
 m_inputFilesPath(op.m_inputFilesPath), m_outputFilePath(op.m_outputFilePath){
     //copying the data
    m_cacheString = op.m_cacheString;
    m_inputFilesPath = op.m_inputFilesPath;
    m_outputFilePath = op.m_outputFilePath;

    // Nulling out the deta of op
   op.m_cacheString = NOT_INITIALIZED;
   op.m_inputFilesPath.clear();
   op.m_outputFilePath = NOT_INITIALIZED;
}

Operation& Operation::operator=(Operation&& op) {

    // Nulling out the deta of op
   op.m_cacheString = NOT_INITIALIZED;
   op.m_inputFilesPath.clear();
   op.m_outputFilePath = NOT_INITIALIZED;

   return *this;
}

void Operation::writeToOutputFile() const {
    if(m_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }
    writeToFile(m_outputFilePath);
}

void Operation::writeToOutputFile(const std::string& content) const {
    if(m_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }
    if (!m_outputFilePath.compare(PRINT)) {//if output is stdout
        std::cout << content << std::endl;
    } else {
        files::writeFileContent(m_outputFilePath, content);
    }
}