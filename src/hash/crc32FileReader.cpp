#include "crc32FileReader.hpp"

uint32_t crc32::crc32(const std::string& filePath) {
    //reads the file as needed
    std::string s =  "";
    s += files::readFileContent(filePath);

    return crc32::crc32FromString(s);
}

uint32_t crc32::crc32FromString(const std::string& file) {
    //because of /0
    unsigned int length = file.length() + 1;

    auto buffer = file.c_str();

    //calculating crc32
    uint32_t result = crc32::crc32(buffer, length -1);

    return result;
}