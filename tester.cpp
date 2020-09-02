#include "CacheOperation.hpp"
#include <iostream>
#include "crc32FileReader.hpp"
#include "CacheManager.hpp"

using namespace std;
int main() {
        try{
    int length = 2;
    const char* argv[] = {"cache", "clear"};
     CacheManager::performOperation(length, argv);
     
    int length2 = 5;
    const char* argv2[] = {"matrix", "add","matrix1", "matrix2","stdout"};
    CacheManager::performOperation(length2, argv2);
    }catch(const std::system_error& e) {
        std::cerr << e.code().message() << std::endl;
    }catch(const exception& e1) {
        cerr<<e1.what()<<endl;
    }catch(const ErrorCodeException& e2) {
        e2.printErrorMessage();
    }
    return 0;
}
