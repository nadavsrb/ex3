#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <iostream>
#include <fstream>
#include <memory>
#include <system_error>
#include <string.h>

#include "CacheManager.hpp"
#include "file_reading.hpp"

#define CACHE_FILE "Cache__DONT_TOUCH_THIS_FILE.txt"
#define CACHE_LINE "CacheManager is running!\n"
#define CACHE_LINE_LENGTH 25

using namespace std;

/**
 * @brief throws an error if the user added a file named like our cache file.
 * if the cache file does not exist the function creates a new one.
 * 
 */
void checkCacheFileExists() {
    // opening the cache file
    const auto cachefd = open(CACHE_FILE, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw system_error{errno, system_category()};
    }

    // to specify that we are in our cache manager file we make sure that the folowing line in the first one
    // or the file is empty (and we will write the line)
    char cacheID[CACHE_LINE_LENGTH + 1];
    cacheID[CACHE_LINE_LENGTH] = '\0';

    int errorID = read(cachefd, cacheID, CACHE_LINE_LENGTH);
    if (errorID == 0) { // empty file
        int errorWriting = write(cachefd, CACHE_LINE, CACHE_LINE_LENGTH);
        if (errorWriting < 0) {
          close(cachefd);
          throw system_error{errno, system_category()}; 
        }
    } else if (errorID > 0 && (strcmp(cacheID, CACHE_LINE) != 0)) { // the file does not start with our line
        close(cachefd);
        throw runtime_error("A file named 'Cache__DONT_TOUCH_THIS_FILE.txt' which is not a cache manager allready exists. Changed it's name and run the program again.");
    } else if (errorID < 0) { // a system error
        close(cachefd);
        throw system_error{errno, system_category()};
    }
    close(cachefd);
}

void CacheManager::performOperation(int argc, const char *argv[]) {
    checkCacheFileExists();

    // performs the operation
    auto operation = make_unique<CacheOperation>(argc, argv);
    operation->writeToOutputFile();

    // writes the operation line into the cache file
    string cacheCopy = ""; 
    if (!operation->isClear()) {
        cacheCopy += readFileContent(CACHE_FILE);
    }

    cacheCopy.erase(0, CACHE_LINE_LENGTH);
    string cache = CACHE_LINE + operation->getCacheString();
    cache += cacheCopy;

    writeFileContent(CACHE_FILE, cache);
}

string CacheManager::search(const shared_ptr<CacheOperation>& operation) {    
    ifstream cacheFile;
    cacheFile.open(CACHE_FILE);
    if (!cacheFile) {
        throw std::system_error();
    }

    // checks if every begining of a line is similar to the CacheString of the operation
    // if it finds the similar one it will return something to print
    string line, operationLine = operation->getCacheString();
    //deleting the time & date & \n form operation (because of the \n there is +1).
    operationLine.erase(operationLine.length() - CurrentTime::TIME_STRING_LENGTH - 1, CurrentTime::TIME_STRING_LENGTH + 1);
    unsigned int i;
    getline(cacheFile, line); //the title
    while (getline(cacheFile, line)) {
        for (i = 0 ; i < line.size() && i < operationLine.size(); ++i) {
            if (line[i] != operationLine[i]) {
                break;
            }
        }
        // all checks completed
        if (i == operationLine.size()) {
            return "result found in cache – saved on " + line.substr(i);
        }
    }

    return "result wasn't found in cache";
}
