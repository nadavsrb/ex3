#pragma once

#include "CacheOperation.hpp"
#include "file_reading.hpp"

#include <iostream>
#include <fstream>
#include <memory>
#include <system_error>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <filesystem>
#include <system_error>
#include <errno.h>

#define CACHE_FILE "src/bin/cache/Cache__DONT_TOUCH_THIS_FILE.txt"
#define CACHE_LINE "Cache Manager is running!\n"
#define FILES_DIR "Cache Manager is running!\n"
#define CACHE_DIR "src/bin/cache"
#define CACHE_FILES_DIR "src/bin/cache/files"
#define CACHE_FILES_DIR_ "src/bin/cache/files/"
#define CACHE_LINE_LENGTH 26

using namespace std;

namespace CacheManager {
    void performOperation(int argc, const char *argv[]);

    string search(const CacheOperation& operation);
}