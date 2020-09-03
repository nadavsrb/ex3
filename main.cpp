#include "CacheManager.hpp"
#include "Operation.hpp"
#include "ImageConvertOperation.hpp"
#include "ImageRotateOperation.hpp"
#include "MatrixֹMultOperation.hpp"
#include "MatrixֹAddOperation.hpp"
#include "ErrorCodeException.hpp"
#include <iostream>

#define NUMBER_OF_ARGUMENTS_ERROR runtime_error("Invalid input! Number of arguments does not suit to the chosen operation.")
#define UNKNOWN_COMMAND runtime_error("Invalid input! Unknown command.")

using namespace std;

int main(int argc, char *argv[]) {

    int startIndex = 0;
    if(argc < 2) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }
    bool isSearch = false;
    bool isClear = false;
    Operation* operation = nullptr;
    try{
    if(strcmp(argv[startIndex],"cache") == 0) {
        if (strcmp(argv[startIndex + 1],"search") == 0) {
            isSearch = true;
            startIndex = 2; //index 0 = cache, index 1 = search - not important from now
            if(argc < 4) {
                throw NUMBER_OF_ARGUMENTS_ERROR;
            }
        } else if (strcmp(argv[startIndex + 1],"clear") == 0){
            isClear = true;
        }
    }else if (strcmp(argv[startIndex],"matrix") == 0) {
        if (strcmp(argv[startIndex + 1],"multiply") == 0) {
            operation =  new MatrixMultOperation(argc - 2,  (const char**) &argv[2], isSearch);
        } else if (strcmp(argv[startIndex + 1],"add") == 0) {
            operation =  new MatrixAddOperation(argc - 2, (const char**)  &argv[2], isSearch);
        }
    } else if (strcmp(argv[startIndex],"hash") == 0) {
        if (strcmp(argv[startIndex + 1],"crc32") == 0) {
            operation =  new MatrixAddOperation(argc - 2,(const char**)  &argv[2], isSearch);
        }
    }else if(strcmp(argv[startIndex],"img") == 0) {
        if (strcmp(argv[startIndex + 1],"rotate") == 0) {
            operation =  new ImageRotateOperation(argc - 2, (const char**) &argv[2], isSearch);
        } else if (strcmp(argv[startIndex + 1],"convert") == 0) {
            operation =  new ImageConvertOperation(argc - 2, (const char**) &argv[2], isSearch);
        }
    } else {
        throw UNKNOWN_COMMAND;
    }


        if (argc == 1) {
            throw runtime_error("Error: must get arguments");
        }
        CacheManager cm = CacheManager(operation);
        cm.performOperation(isSearch, isClear);
    } catch (const exception& e1) {
        cerr<<e1.what()<<endl;
    } catch (const ErrorCodeException& e2) {
        e2.printErrorMessage();
    }

    if(operation != nullptr){
        delete operation;  
    }
    return 0;
}