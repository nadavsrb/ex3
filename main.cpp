#include "CacheManager.hpp"
#include "ErrorCodeException.hpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    try{
        if(argc == 1) {
            throw runtime_error("Error: must get arguments");
        }
        CacheManager::performOperation(argc - 1, (const char **)&argv[1]);
    } catch (const exception& e1) {
        cerr<<e1.what()<<endl;
    } catch (const ErrorCodeException& e2) {
        e2.printErrorMessage();
    }
    return 0;
}