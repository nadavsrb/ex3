#include "HashCrc32Operation.hpp"

using namespace cache::operatorsHelpingFuncs;
using namespace cache::operation;

    HashCrc32Operation::HashCrc32Operation(const int argc, const char *argv[], bool isSearched /*= false*/){
        //fixing the expected args if the operation is from search.
        int argsExpected = argc;
        if (isSearched) {
            ++argsExpected;
        }

        //exceptions
        if (argsExpected != 2) {//1 input file & 1 output file
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }

        //if not searched operatin intalize the output file.
        m_inputFilesPath.push_back(copyToString(argv[START_INDEX]));

        if (!isSearched) {
            m_outputFilePath = copyToString(argv[START_INDEX + 1]);
            if(m_outputFilePath.find('.') == std::string::npos && m_outputFilePath.compare("stdout") != 0) {
                throw std::runtime_error("Output file must have a type or be 'stdout'.");
            }
        }
    
         //Calculating the _cacheString.
        m_cacheString = getCacheCode() + " " + std::to_string(crc32::crc32(m_inputFilesPath.at(START_INDEX)));
    }
    
    std::string HashCrc32Operation::getOutputFileType() const { return "txt"; }

    std::string HashCrc32Operation::getCacheCode() const { return "hash_crc32"; }

    std::string HashCrc32Operation::getCacheString() const { return m_cacheString; }

    void HashCrc32Operation::writeToFile(const std::string& fileName) const {
        if(m_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
            return;
        }
        std::string result = "";
        result += std::to_string(crc32::crc32(m_inputFilesPath.at(START_INDEX)));

        if (fileName.compare(PRINT)  == 0) {
            std::cout << result << std::endl;
        } else {
            files::writeFileContent(fileName, result);
        }
    }