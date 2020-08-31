#include "CacheManager.hpp"
#include <iostream>

using namespace std;
int main() {
    int length = 2;
    const char* argv[] = {"cache", "clear"};
     CacheManager::performOperation(length, argv);

    int length1 = 4;
    const char* argv1[] = {"hash", "crc32","matrix1.txt","stdout"};
     CacheManager::performOperation(length1, argv1);

     int length2 = 5;
    const char* argv2[] = {"matrix", "multiply","matrix1.txt", "matrix2.txt","stdout"};
     CacheManager::performOperation(length2, argv2);

     int length3 = 5;
    const char* argv3[] = {"matrix", "add","matrix1.txt", "matrix2.txt","stdout"};
     CacheManager::performOperation(length3, argv3);
     
     int length4 = 4;
    const char* argv4[] = {"image", "convert","lena-color.bmp","convert.bmp"};
     CacheManager::performOperation(length4, argv4);

     int length5 = 4;
    const char* argv5[] = {"image", "rotate","lena-color.bmp", "rotate.bmp"};
     CacheManager::performOperation(length5, argv5);

    int length6 = 7;
    const char* argv6[] = {"cache", "search", "matrix", "multiply","matrix1.txt", "matrix2.txt","stdout"};
     CacheManager::performOperation(length6, argv6);
     
    return 0;
}
