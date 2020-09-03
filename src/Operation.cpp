#include "Operation.hpp"

void Operation::writeToOutputFile() const {
    if(_outputFilePath.compare("") == 0) {//no output file
        return;
    }
    writeToFile(_outputFilePath);
}

void Operation::writeToOutputFile(const string& content) const {
    if(_outputFilePath.compare("") == 0) {//no output file
        return;
    }
    if (!_outputFilePath.compare(PRINT)) {
        cout << content << endl;
    } else {
        writeFileContent(_outputFilePath, content);
    }
}