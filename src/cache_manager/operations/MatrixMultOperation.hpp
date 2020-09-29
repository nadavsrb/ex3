#pragma once

#include "crc32FileReader.hpp"
#include "Operation.hpp"
#include "MatrixClass.hpp"

#include <memory>

/**
 * @brief This class stands for the "matrix mult" operation.
 */
namespace cache {
namespace operation{
class MatrixMultOperation : public Operation {
public:
    /**
     * @brief Construct a new Matrix Mult Operation object.
     * 
     * @param argc the lenght of the input (argv).
     * @param argv includes the input files (& the output file if not from searched operation).
     * @param isSearched true if the originall operation was search,else false.
     */
    MatrixMultOperation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const override;

    string getCacheCode() const override;

    string getCacheString() const override;

    void writeToFile(const string& fileName) const override;
};
}
}