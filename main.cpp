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

int main(int argc, char *argv[]) {
    // first arg in ex3.out and we don't need it
    int startIndex = 1;
    argc -= 1;

    // to few arguments
    if (argc < 3 && !(argc == 2 && strcmp(argv[startIndex + 1], "clear") == 0)) {
        throw NUMBER_OF_ARGUMENTS_ERROR;
    }

    bool isSearch = false;
    bool isClear = false;
    unique_ptr<Operation> operation;
    try {
        // if the operation is a chace operation (search / clear):
        if (strcmp(argv[startIndex], "cache") == 0) {
            // search
            if (strcmp(argv[startIndex + 1], "search") == 0) {
                isSearch = true;
                startIndex += 2; //index 0 = cache, index 1 = search - not important from now
                argc -= 2;
                if (argc < 3) {
                    throw NUMBER_OF_ARGUMENTS_ERROR;
                }
            } else if (strcmp(argv[startIndex + 1], "clear") == 0) { // clear
                isClear = true;
            } else {
                throw UNKNOWN_COMMAND;
            }
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

    return 0;
}