#pragma once

#include "CacheManager.hpp"
#include "CurrentTime.hpp"
#include "StringFunctions.hpp"
#include "crc32FileReader.hpp"

#include <string>
#include <memory>
#include <vector>
#include <string.h>
#include <iostream>

#define NUMBER_OF_ARGUMENTS_ERROR runtime_error("Invalid input! Number of arguments does not suit to the chosen operation.")
#define UNKNOWN_COMMAND runtime_error("Invalid input! Unknown command.")
#define PRINT "stdout"

using namespace std;

class Operation {
public:
    virtual bool isClear() { return false; }
    virtual bool isSearch() { return false; }
    
    virtual string getOutputFileType() = 0;
    virtual string getCacheCode() = 0;
    virtual string getCacheString() = 0;

    void writeToOutputFile() const; //if the methode isn't a cache methode
    void writeToOutputFile(const string& content) const;
    virtual void writeToFile(const string& fileName) = 0;

protected:
    string _cacheString = "";
    vector<string> _inputFilesPath;
    string _outputFilePath;
    int _OperationID = 0;
};