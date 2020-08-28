#include "crc32.h"
#include <iostream>
#include <string>
#include <fstream>

namespace std {

uint32_t crc32(const string& filePath) {
    std::ifstream inp {filePath, std::ios_base::binary};

    // checking for system error (file doesn't open)
    if (!inp) {
        throw std::system_error();
    }

    // checking if the file is empty
    if (inp.peek() == std::ifstream::traits_type::eof()) {
        inp.close();
        throw std::runtime_error("The file in empty. Can not convert into matrix.");
    }
    unsigned char buffer[(unsigned int) inp.tellg()];
    inp.read((char*)&buffer, sizeof(buffer));
    inp.close();

    return calculate_crc32c(0, buffer, (unsigned int) inp.tellg());
}

}