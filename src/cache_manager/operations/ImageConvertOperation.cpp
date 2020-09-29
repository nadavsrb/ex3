#include "ImageConvertOperation.hpp"

using namespace cache::operatorsHelpingFuncs;
using namespace cache::operation;

ImageConvertOperation::ImageConvertOperation(const int argc, const char *argv[], bool isSearched /*= false*/){
    //fixing the expected args if the operation is from search.
    int argsExpected = argc;
    if (isSearched) {
        ++argsExpected;
    }

    //exceptions
    if (argsExpected != 2) {// 1 input file & 1 output file
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    if (!typed(argv[START_INDEX], "bmp")) {
        throw std::runtime_error("Image files must be with type '.bmp'.");
    }

    //saves the data from the command
    m_inputFilesPath.push_back(copyToString(argv[START_INDEX]));

    //if not searched operatin intalize the output file.
    if (!isSearched) {
        if (typed(argv[START_INDEX], "bmp")) {
            m_outputFilePath = copyToString(argv[START_INDEX + 1]);
        } else {
            throw std::runtime_error("Image files must be with type '.bmp'.");
        }
    }

     //Calculating the _cacheString.
    m_cacheString = getCacheCode() + " " + std::to_string(crc32::crc32(m_inputFilesPath.at(START_INDEX)));
}

string ImageConvertOperation::getOutputFileType() const { return "bmp"; }

string ImageConvertOperation::getCacheCode() const { return "image_convert"; }

string ImageConvertOperation::getCacheString() const { return m_cacheString; }

void ImageConvertOperation::writeToFile(const string& fileName) const {
    if(m_outputFilePath.compare(NOT_INITIALIZED) == 0) {//no output file
        return;
    }
    testing::bmp::convert_to_grayscale(m_inputFilesPath.at(START_INDEX), fileName);
}