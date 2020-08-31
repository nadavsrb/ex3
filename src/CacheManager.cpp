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

#define CACHE_FILE "src/bin/cashe/Cache__DONT_TOUCH_THIS_FILE.txt"
#define CACHE_LINE "CacheManager is running!\n"
#define FILES_DIR "CacheManager is running!\n"
#define CACHE_LINE_LENGTH 25

using namespace std;

/**
 * @brief throws an error if the user added a file named like our cache file.
 * if the cache file does not exist the function creates a new one.
 * 
 */
void checkCacheFileExists() {
    //make the dir cache
    mkdir("src/bin/cashe", 0777);
    //make the dir for the cache files
    mkdir("src/bin/cashe/files", 0777);
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

void createBeckupFile(const CacheOperation& operation, unsigned int index) {
    string fileName = "src/bin/cashe/files/" + std::to_string(index) + "." + operation.getOutputFileType();
    const auto cachefd = open(fileName.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw system_error{errno, system_category()};
    }
    operation.writeToFile(fileName);
}

uint32_t getCashFileIndex() {
    ifstream cacheFile;
    cacheFile.open(CACHE_FILE);
    if (!cacheFile) {
        throw std::system_error();
    }

    string line;

    getline(cacheFile, line); //the title
    if (cacheFile.peek() == std::ifstream::traits_type::eof()) {
        cacheFile.close();
        return 0;
    }

    getline(cacheFile, line);
    cacheFile.close();
    return std::stoi(line.substr(line.find("|") + 1)) + 1;
}

void CacheManager::performOperation(int argc, const char *argv[]) {
    checkCacheFileExists();

    // performs the operation
    auto operation = make_unique<CacheOperation>(argc, argv);
    operation->writeToOutputFile();

    // writes the operation line into the cache file
    string cacheCopy = "";
    if (operation->isClear()) {
        int errorRemove = remove(CACHE_FILE);
        if (errorRemove < 0) {
          throw system_error{errno, system_category()}; 
        }
    } else if (!operation->isSearch()) {
        cacheCopy += readFileContent(CACHE_FILE);
        cacheCopy.erase(0, CACHE_LINE_LENGTH);
        string cache = CACHE_LINE + operation->getCacheString();
        unsigned int index = getCashFileIndex();
        cache += "|" + std::to_string(index);
        cache += "\n";//end of line
        cache += cacheCopy;

        writeFileContent(CACHE_FILE, cache);

        createBeckupFile(*operation, index);
    }
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
    unsigned int i;
    getline(cacheFile, line); //the title
    while (getline(cacheFile, line)) {
        for (i = 0 ; i < line.size() && i < operationLine.size() && line[i] != ','; ++i) {
            if (line[i] != operationLine[i]) {
                break;
            }
        }
        // all checks completed
        if (line.at(i) == ',') {
            return line.substr(i + 1);
        }
    }

    return ""; //didn't find
}
