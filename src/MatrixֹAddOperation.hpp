#include "Operation.hpp"
#include "MatrixClass.hpp"

class MatrixAddOperation : public Operation {
public:
    MatrixAddOperation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const;
    string getCacheCode() const;
    string getCacheString() const;

    void writeToOutputFile() const; //if the methode isn't a cache methode
    void writeToOutputFile(const string& content) const;
    void writeToFile(const string& fileName) const;
};