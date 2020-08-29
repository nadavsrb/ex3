#include "crc32FileReader.hpp"

uint32_t crc32(const string& filePath) {
    std::ifstream inp;
    inp.open(filePath);

    // checking for system error (file doesn't open)
    if (!inp) {
        throw std::system_error();
    }
    
    inp.seekg(0,std::ios_base::end);

    unsigned int length = inp.tellg();
    inp.seekg (0, std::ios_base::beg);

    unsigned char* buffer = new unsigned char [length];
    inp.read((char*)buffer, length);

    return calculate_crc32c(0, buffer, length);
}