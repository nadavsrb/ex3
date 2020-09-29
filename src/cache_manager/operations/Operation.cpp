#include "Operation.hpp"

using namespace std;

using namespace cache::operation;

Operation::Operation(const Operation& op) : m_cacheString(op.m_cacheString),
 m_inputFilesPath(op.m_inputFilesPath), m_outputFilePath(op.m_outputFilePath){}

Operation& Operation::operator=(const Operation& op) {
    //copying the data
    m_cacheString = op.m_cacheString;
    m_inputFilesPath = op.m_inputFilesPath;
    m_outputFilePath = op.m_outputFilePath;

    return *this;
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

void Operation::writeToOutputFile(const string& content) const {
    if(m_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }
    if (!m_outputFilePath.compare(PRINT)) {//if output is stdout
        cout << content << endl;
    } else {
        files::writeFileContent(m_outputFilePath, content);
    }
}