#pragma once

#include "CacheManager.hpp"
#include "CurrentTime.hpp"
#include "StringFunctions.hpp"
#include "crc32FileReader.hpp"
#include "file_reading.hpp"

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
    /**
     * @brief Get the type of the output file.
     * 
     * @return string 
     */
    virtual string getOutputFileType() const = 0;
    /**
     * @brief Get the Cache Code of the object (the begining of the CacheString).
     * 
     * @return string 
     */
    virtual string getCacheCode() const = 0;
    /**
     * @brief Get the Cache String of the object (what we write on our cache file).
     * 
     * @return string 
     */
    virtual string getCacheString() const = 0;

    /**
     * @brief Writes the result to the output file.
     * 
     */
    void writeToOutputFile() const;
    /**
     * @brief Writes to the output file.
     * 
     * @param content - what it will write to the file.
     */
    void writeToOutputFile(const string& content) const;
    /**
     * @brief Writes the result of the operation.
     * 
     * @param fileName - the name of the file we write to.
     */
    virtual void writeToFile(const string& fileName) const = 0;

    /**
     * @brief Destroy the Operation object.
     * 
     */
    virtual ~Operation() = default;

protected:
    string _cacheString = "";
    vector<string> _inputFilesPath;
    string _outputFilePath = "";//no output file
};