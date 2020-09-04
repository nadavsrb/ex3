#include "CacheManager.hpp"
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

int main(int argc,const char *argv[]) {
    // first arg is ex3.out and we don't need it
    int startIndex = 1;
    --argc;

    unique_ptr<Operation> operation;
    bool isSearch = CacheManager::isSearch(argc, argv + startIndex);
    bool isClear = CacheManager::isClear(argc, argv + startIndex);

    if (isSearch) {
        // first two words are "cache search", moving on to the operation
        startIndex += 2;
        argc -= 2;
    }
    
    try {
        // to few arguments:
        //if not clear now we must have name ("matrix"),
        //operation ("add"), at list one input file.
        if (argc < 3 && !isClear) { 
            throw UNKNOWN_COMMAND;
        }

        // regular operations
        if (!isClear) {
            // matrix operations
            if (strcmp(argv[startIndex], "matrix") == 0) {
                if (strcmp(argv[startIndex + 1], "multiply") == 0) { // matrix multiply
                    operation =  make_unique<MatrixMultOperation>(argc - 2, &argv[startIndex + 2], isSearch);
                } else if (strcmp(argv[startIndex + 1], "add") == 0) { // matrix add
                    operation =  make_unique<MatrixAddOperation>(argc - 2, &argv[startIndex + 2], isSearch);
                }
            // hash operations
            } else if (strcmp(argv[startIndex], "hash") == 0) {
                if (strcmp(argv[startIndex + 1], "crc32") == 0) { // hash crc32
                    operation =  make_unique<HashCrc32Operation>(argc - 2, &argv[startIndex + 2], isSearch);
                }
            // image operations
            } else if (strcmp(argv[startIndex], "image") == 0) {
                if (strcmp(argv[startIndex + 1], "rotate") == 0) { // image rotate
                    operation =  make_unique<ImageRotateOperation>(argc - 2, &argv[startIndex + 2], isSearch);
                } else if (strcmp(argv[startIndex + 1], "convert") == 0) { // image convert
                    operation =  make_unique<ImageConvertOperation>(argc - 2, &argv[startIndex + 2], isSearch);
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