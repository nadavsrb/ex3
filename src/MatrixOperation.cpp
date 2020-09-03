#include "MatrixOperation.hpp"

MatrixOperation::MatrixOperation(const int argc, const char *argv[], bool isSearched /*= false*/) {}
    
string MatrixOperation::getOutputFileType() {}
string MatrixOperation::getCacheCode() {}

void MatrixOperation::writeToOutputFile() {} //if the methode isn't a cache methode
void MatrixOperation::writeToOutputFile(const string& content) {}
void MatrixOperation::writeToFile(const string& fileName) {}