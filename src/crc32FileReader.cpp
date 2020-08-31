#include "crc32FileReader.hpp"

#include <iostream>

using namespace std;

uint32_t crc32(const string& filePath) {
    string s = readFileContent(filePath);

    //for making the windows text file like linux txt file
    s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());

    return crc32FromString(s);
}

uint32_t crc32FromString(const string& file) {
    //because of /0
    unsigned int length = file.length() + 1;

   // declaring character array 
    char *buffer = new char[length];
  
    // copying the contents of the 
    // string to char array 
    strcpy(buffer, file.c_str());

    uint32_t result = crc32((unsigned char *) buffer, length -1);

    delete[] buffer;
    return result;
}