#pragma once

#include "crc32FileReader.hpp"
#include "Operation.hpp"
#include "bmp_tester.hpp"

/**
 * @brief This class stands for the "image convert" operation.
 */
namespace cache {
namespace operation{
class ImageConvertOperation : public Operation {
public:
    /**
     * @brief Construct a new Image Convert Operation object.
     * 
     * @param argc the lenght of the input (argv).
     * @param argv includes the input files (& the output file if not from searched operation).
     * @param isSearched true if the originall operation was search,else false.
     */
    ImageConvertOperation(const int argc, const char *argv[], bool isSearched = false);
    
    string getOutputFileType() const override;
    string getCacheCode() const override;
    string getCacheString() const override;

    void writeToFile(const string& fileName) const override;
};
}
}