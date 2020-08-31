#include "CacheOperation.hpp"
#include <iostream>

using namespace std;
int main() {
    int length = 4;
    const char* argv[] = {"image", "rotate","lena-color.bmp","result.bmp"};

    CacheOperation co = CacheOperation(length, argv);

    co.writeToOutputFile();
    return 0;
}
