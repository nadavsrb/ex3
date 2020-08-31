#include "crc32FileReader.hpp"

#include <iostream>

using namespace std;

uint32_t crc32(const string& filePath) {
    string s = readFileContent(filePath);

    //for making the windows text file like linux txt file
    s.erase(std::remove(s.begin(), s.end(), '\r'), s.end());

    //because of /0
    unsigned int length = s.length() + 1;

   // declaring character array 
    char *buffer = new char[length];
  
    // copying the contents of the 
    // string to char array 
    strcpy(buffer, s.c_str());

    return crc32((unsigned char *) buffer, length -1);
}