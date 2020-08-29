#include "crc32FileReader.hpp"

uint32_t crc32(const string& filePath) {
    string s = readFileContent(filePath);

    //because of /0
    unsigned int lenght = s.length() + 1;

   // declaring character array 
    char *buffer = new char[lenght];
  
    // copying the contents of the 
    // string to char array 
    strcpy(buffer, s.c_str());

    return calculate_crc32c(0, (unsigned char *) buffer, lenght - 1);
}