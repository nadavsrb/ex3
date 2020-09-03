#include "Operation.hpp"

class MatrixOperation : public Operation {
public:
    MatrixOperation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType();
    string getCacheCode();

    void writeToOutputFile(); //if the methode isn't a cache methode
    void writeToOutputFile(const string& content);
    void writeToFile(const string& fileName);
};