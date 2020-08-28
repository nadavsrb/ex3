#include "MatrixClass.hpp"
#include "bmp_tester.hpp"
#include <string>
#include <iostream>


int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 5) {
        std::cerr << "Invalid input! Too few arguments." << std::endl;
    } else if (argv[0] == "matrix") {
        if (argv[1] == "multiply") {
            // call the function
        } else if (argv[1] == "add") {
            // call the function
        } else {
            std::cerr << "Invalid input! Unknown command \"" << argv[0] << " " << argv[1] << "\"." << std::endl;
        }
    } else if (argv[0] == "image") {
        if (argv[1] == "rotate") {
            // call the function
        } else if (argv[1] == "convert") {
            // call the function
        } else {
            std::cerr << "Invalid input! Unknown command \"" << argv[0] << " " << argv[1] << "\"." << std::endl;
        }
    } else if (argv[0] == "hash") {
        if (argv[1] == "crc32") {
            // call the function
        } else {
            std::cerr << "Invalid input! Unknown command \"" << argv[0] << " " << argv[1] << "\"." << std::endl;
        }
    } else if (argv[0] == "cache") {
        if (argv[1] == "clear") {
            // call the function
        } else if (argv[1] == "search") {
            // call the function
        } else {
            std::cerr << "Invalid input! Unknown command \"" << argv[0] << " " << argv[1] << "\"." << std::endl;
        }
    } else {
        std::cerr << "Invalid input! Unknown command \"" << argv[0] << "\"." << std::endl;
    }
    return 0;
}