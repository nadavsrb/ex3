#include "CacheManager.hpp"
#include <iostream>

using namespace std;
int main() {
    // testing matrix commands
    int length[] = {5, 5, 4, 4, 4};
    const char* mult_argv[][5] = {
        {"matrix", "multiply", "matrix_mult1.txt", "matrix_mult2.txt", "stdout"}, 
        {"matrix", "add", "matrix_add1.txt", "matrix_add2.txt", "stdout"},
        {"image", "convert", "image_convert.bmp", "stdout"},
        {"image", "rotate", "image_rotate.bmp", "stdout"},
        {"hash", "crc32", "crc.txt", "stdout"}};
    for (unsigned int j = 0; j < 3; ++j) {
        for (unsigned int i = 0; i < 5; ++i) {
            try {
                CacheManager::performOperation(length[i], *(mult_argv + i));
            } catch (const exception& ec) {
                cout << ec.what() << endl;
            } catch (const ErrorCodeException& e2) {
                e2.printErrorMessage();
            }
        }
    }

/*
    int length = 2;
    const char* argv[] = {"cache", "clear"};
     CacheManager::performOperation(length, argv);

    int length1 = 4;
    const char* argv1[] = {"hash", "crc32","matrix1.txt","stdout"};
     CacheManager::performOperation(length1, argv1);

     int length2 = 5;
    const char* argv2[] = {"matrix", "multiply","matrix1.txt", "matrix2.txt","result-matrix.txt"};
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

    int length6 = 6;
    const char* argv6[] = {"cache", "search", "matrix", "multiply","matrix1.txt", "matrix2.txt"};
     CacheManager::performOperation(length6, argv6);

    int length7 = 5;
    const char* argv7[] = {"matrix", "multiply","matrix1.txt", "matrix1.txt", "stdout"};
    CacheManager::performOperation(length7, argv7);
     */
    return 0;
}
