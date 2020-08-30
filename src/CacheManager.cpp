#include "CacheOperation.hpp"
#include "file_reading.hpp"
#include <memory>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <system_error>

#define CACHE_FILE "Cache__DONT_TOUCH_THIS_FILE.txt"
#define CACHE_LINE "CacheManager is running!\n"
#define CACHE_LINE_LENGTH 26

using namespace std;

void CacheManager::performOperation(int argc, const char *argv[]) {
    // opening the cache file
    const auto cachefd = open(CACHE_FILE, O_CREAT, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw system_error{errno, system_category()};
    }

    // to specify that we are in our cache manager file we make sure that the folowing line in the first one
    // or the file is empty (and we will write the line)
    char cacheID[] = { CACHE_LINE };

    int errorID = read(cachefd, cacheID, sizeof(cacheID));
    if (errorID == 0) { // empty file
        write(cachefd, cacheID, sizeof(cacheID));
        close(cachefd);
    } else if (errorID > 0 && !strcmp(cacheID, CACHE_LINE)) { // the file does not start with our line
        close(cachefd);
        throw runtime_error("A file named 'Cache__DONT_TOUCH_THIS_FILE.txt' which is not a cache manager allready exists. Changed it's name and run the program again.");
    } else if (errorID < 0) { // a system error
        close(cachefd);
        throw system_error{errno, system_category()};
    } else {
        close(cachefd);
    }

    // performs the operation and writes the operation line into the cache file
    auto operation = make_unique<CacheOperation>(argc, argv);
    operation.writeToOutputFile();
    string cache = readFileContent(CACHE_FILE);
    cache.erase(0, CACHE_LINE_LENGTH - 1);
    cache = CACHE_LINE + operation->getCacheString() + cache;
    writeFileContent(CACHE_FILE, cache);
}