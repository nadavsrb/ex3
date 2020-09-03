#include "Operation.hpp"

void Operation::writeToOutputFile() const {
    writeToFile(_outputFilePath);
}

void Operation::writeToOutputFile(const string& content) const{
    if (!_outputFilePath.compare(PRINT)) {
        cout << content << endl;
    } else {
        writeFileContent(_outputFilePath, content);
    }
}