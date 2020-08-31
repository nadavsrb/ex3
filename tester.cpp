#include "CacheOperation.hpp"
#include <iostream>

using namespace std;
int main() {
    int length = 5;
    const char* argv[] = {"matrix", "multiply","matrix1.txt","matrix2.txt","mult_result.txt"};

    CacheOperation co = CacheOperation(length, argv);

    co.writeToOutputFile();
    return 0;
}
