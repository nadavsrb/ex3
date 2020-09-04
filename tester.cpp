#include "CacheManager.hpp"
#include "Operation.hpp"
#include "ImageConvertOperation.hpp"
#include "ImageRotateOperation.hpp"
#include "MatrixֹMultOperation.hpp"
#include "MatrixֹAddOperation.hpp"
#include "HashCrc32Operation.hpp"
#include "ErrorCodeException.hpp"

#include <iostream>
#include <memory>
#include <string.h>

using namespace std;

void test(int argc, const char *argv[]) {
    int startIndex = 0;

    unique_ptr<Operation> operation;
    bool isSearch = CacheManager::isSearch(argc, argv + startIndex);
    bool isClear = CacheManager::isClear(argc, argv + startIndex);

    if (isSearch) {
        // first two words are "cache search", moving on to the operation
        startIndex += 2;
        argc -= 2;
    }
    
    try {
        // to few arguments
        if (argc < 2 && !isClear) {
            throw NUMBER_OF_ARGUMENTS_ERROR;
        }

        // regular operations
        if (!isClear) {
            // matrix operations
            if (strcmp(argv[startIndex], "matrix") == 0) {
                if (strcmp(argv[startIndex + 1], "multiply") == 0) { // matrix multiply
                    operation =  make_unique<MatrixMultOperation>(argc - 2,  (const char**) &argv[startIndex + 2], isSearch);
                } else if (strcmp(argv[startIndex + 1], "add") == 0) { // matrix add
                    operation =  make_unique<MatrixAddOperation>(argc - 2, (const char**)  &argv[startIndex + 2], isSearch);
                }
            // hash operations
            } else if (strcmp(argv[startIndex], "hash") == 0) {
                if (strcmp(argv[startIndex + 1], "crc32") == 0) { // hash crc32
                    operation =  make_unique<HashCrc32Operation>(argc - 2,(const char**)  &argv[startIndex + 2], isSearch);
                }
            // image operations
            } else if (strcmp(argv[startIndex], "image") == 0) {
                if (strcmp(argv[startIndex + 1], "rotate") == 0) { // image rotate
                    operation =  make_unique<ImageRotateOperation>(argc - 2, (const char**) &argv[startIndex + 2], isSearch);
                } else if (strcmp(argv[startIndex + 1], "convert") == 0) { // image convert
                    operation =  make_unique<ImageConvertOperation>(argc - 2, (const char**) &argv[startIndex + 2], isSearch);
                }
            // an operation that doesn't exists
            } else {
               throw UNKNOWN_COMMAND;
            }
        }

        CacheManager cm(operation);
        cm.performOperation(isSearch, isClear);
    // if an error was thrown we will send a message in stderr
    } catch (const exception& e1) {
        cerr << e1.what() << endl;
    } catch (const ErrorCodeException& e2) {
        e2.printErrorMessage();
    }
}

int main() {
    // testing matrix commands
    int length[] = {5, 5, 4, 4, 4};
    int searchl[] = {6, 1, 5, 3, 2};
    const char* argv[][5] = {
        {"matrix", "multiply", "matrix_mult1.txt", "matrix_mult2.txt", "stdout"}, 
        {"matrix", "add", "matrix_add1.txt", "matrix_add2.txt", "stdout"},
        {"image", "convert", "image_convert.bmp", "result_convert.bmp"},
        {"image", "rotate", "image_rotate.bmp", "result_rotate.bmp"},
        {"hash", "crc32", "crc.txt", "stdout"}
        };
    const char* search[][7] = {
        {"cache", "search", "matrix", "multiply", "matrix_mult1.txt", "matrix_mult2.txt"}, 
        {"cache"},
        {"cache", "search", "matrix", "multiply", "matrix_mult1.txt"},
        {"cache", "search", "image"},
        {"cache", "search"}
        };
    const char* f[][2] ={{"cache", "clear"}};
    test(2, *(f));
    test(2, *(f));
    for (int j = 0; j<2; ++j){
        for (unsigned int i = 0; i < 5; ++i) {
            test(length[i], *(argv + i));
            test(searchl[i], *(search + i));
        }
    cout << endl;
    }
    const char* arg[2] = {"cache", "search"};
    test(2, arg);
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
