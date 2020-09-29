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

   // declaring character array 
    char *buffer = new char[length];

    // copying the contents of the 
    // string to char array 
    strcpy(buffer, file.c_str());

    //calculating crc32
    uint32_t result = crc32::crc32((unsigned char *) buffer, length -1);

    //deletes the buffer 
    delete[] buffer;
    return result;
}