#pragma once

#include "crc32FileReader.hpp"
#include "Operation.hpp"

/**
 * @brief This class stands for the "hash crc32" operation.
 */
namespace cache {
namespace operation{
class HashCrc32Operation : public Operation {
public:
    /**
     * @brief Construct a new Hash Crc 3 2 Operation object.
     * 
     * @param argc the lenght of the input (argv).
     * @param argv includes the input files (& the output file if not from searched operation).
     * @param isSearched true if the originall operation was search,else false.
     */
    HashCrc32Operation(const int argc, const char *argv[], bool isSearched = false);
    
    std::string getOutputFileType() const override;
    std::string getCacheCode() const override;
    std::string getCacheString() const override;

    void writeToFile(const std::string& fileName) const override;
};
}
}