#include "CacheManager.hpp"
#include "Operation.hpp"
#include "ImageConvertOperation.hpp"
#include "ImageRotateOperation.hpp"
#include "MatrixֹMultOperation.hpp"
#include "MatrixֹAddOperation.hpp"
#include "HashCrc32Operation.hpp"
#include "ErrorCodeException.hpp"
#include <iostream>

#define NUMBER_OF_ARGUMENTS_ERROR runtime_error("Invalid input! Number of arguments does not suit to the chosen operation.")
#define UNKNOWN_COMMAND runtime_error("Invalid input! Unknown command.")

using namespace std;

void test(int argc, const char *argv[]) {
    int startIndex = 0;
    if(argc < 3 && !(strcmp(argv[startIndex + 1],"clear") == 0 && argc == 2)) {//..
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }
    bool isSearch = false;
    bool isClear = false;
    unique_ptr<Operation> operation;
    try{
        //cache operations
        if(strcmp(argv[startIndex],"cache") == 0) {
            if (strcmp(argv[startIndex + 1],"search") == 0) {
                isSearch = true;
                startIndex += 2; //index 0 = cache, index 1 = search - not important from now //..
                argc -= 2;//..
                if(argc < 3) {
                    throw NUMBER_OF_ARGUMENTS_ERROR;
                }
            } else if (strcmp(argv[startIndex + 1],"clear") == 0){
                isClear = true;
            }else {
                throw UNKNOWN_COMMAND;
            }
        }
        //other operation
        if(!isClear) {
            if (strcmp(argv[startIndex],"matrix") == 0) {
                if (strcmp(argv[startIndex + 1],"multiply") == 0) {
                    operation =  make_unique<MatrixMultOperation>(argc - 2,  (const char**) &argv[startIndex + 2], isSearch);
                } else if (strcmp(argv[startIndex + 1],"add") == 0) {
                    operation =  make_unique<MatrixAddOperation>(argc - 2, (const char**)  &argv[startIndex + 2], isSearch);
                }
            } else if (strcmp(argv[startIndex],"hash") == 0) {
                if (strcmp(argv[startIndex + 1],"crc32") == 0) {
                    operation =  make_unique<HashCrc32Operation>(argc - 2,(const char**)  &argv[startIndex + 2], isSearch);
                }
            }else if(strcmp(argv[startIndex],"image") == 0) {
                if (strcmp(argv[startIndex + 1],"rotate") == 0) {
                    operation =  make_unique<ImageRotateOperation>(argc - 2, (const char**) &argv[startIndex + 2], isSearch);
                } else if (strcmp(argv[startIndex + 1],"convert") == 0) {
                    operation =  make_unique<ImageConvertOperation>(argc - 2, (const char**) &argv[startIndex + 2], isSearch);
                }
            } else {
               throw UNKNOWN_COMMAND;
            }
        }
        CacheManager cm(operation);
        cm.performOperation(isSearch, isClear);
    } catch (const exception& e1) {
        cerr<<e1.what()<<endl;
    } catch (const ErrorCodeException& e2) {
        e2.printErrorMessage();
    }
}

int main() {
    // testing matrix commands
    int length[] = {5, 5, 4, 4, 4};
    const char* argv[][5] = {
        {"matrix", "multiply", "matrix_mult1.txt", "matrix_mult2.txt", "stdout"}, 
        {"matrix", "add", "matrix_add1.txt", "matrix_add2.txt", "stdout"},
        {"image", "convert", "image_convert.bmp", "result_convert.bmp"},
        {"image", "rotate", "image_rotate.bmp", "result_rotate.bmp"},
        {"hash", "crc32", "crc.txt", "stdout"}
        };
    const char* search[][6] = {
        {"cache", "search", "matrix", "multiply", "matrix_mult1.txt", "matrix_mult2.txt"}, 
        {"cache", "search", "matrix", "add", "matrix_add1.txt", "matrix_add2.txt"},
        {"cache", "search", "image", "convert", "image_convert.bmp"},
        {"cache", "search", "image", "rotate", "image_rotate.bmp"},
        {"cache", "search", "hash", "crc32", "crc.txt"}
        };
const char* f[][2] ={{"cache", "clear"}};
        test(2, *(f));
        for (int j = 0; j<2; ++j){
        for (unsigned int i = 0; i < 5; ++i) {
            test(length[i], *(argv + i));
            test(length[i]+1, *(search + i));
        }
        }
        cout << endl;

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
