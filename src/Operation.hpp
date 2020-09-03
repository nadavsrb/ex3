#pragma once

#include "CacheManager.hpp"
#include "CurrentTime.hpp"

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
    Operation(const int argc, const char *argv[], bool isSearched = false) {}
    
    virtual bool isClear() { return false; }
    virtual bool isSearch() { return false; }
    
    virtual string getOutputFileType() = 0;
    virtual string getCacheCode() = 0;

    virtual void writeToOutputFile() = 0; //if the methode isn't a cache methode
    virtual void writeToOutputFile(const string& content) = 0;
    virtual void writeToFile(const string& fileName) = 0;

private:
    string _cacheString = "";
    vector<string> _inputFilesPath;
    string _inputFilePath;
};