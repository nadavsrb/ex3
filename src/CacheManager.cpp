#include "CacheManager.hpp"

using namespace std;

CacheManager::CacheManager(unique_ptr<Operation>& op) {
    _operation = move(op);
}

/**
 * @brief throws an error if the user added a file named like our cache file.
 * if the cache file does not exist the function creates a new one.
 * 
 */
void checkCacheFileExists() {
    //make the dir cache
    mkdir(CacheManager::CACHE_DIR, 0777);
    //make the dir for the cache files
    mkdir(CacheManager::CACHE_FILES_DIR, 0777);
    // opening the cache file
    const auto cachefd = open(CacheManager::CACHE_FILE, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw system_error{errno, system_category()};
    }

    // to specify that we are in our cache manager file we make sure that the folowing line in the first one
    // or the file is empty (and we will write the line)
    char cacheID[CacheManager::CACHE_LINE_LENGTH + 1];
    cacheID[CacheManager::CACHE_LINE_LENGTH] = '\0';

    int errorID = read(cachefd, cacheID, CacheManager::CACHE_LINE_LENGTH);
    if (errorID == 0) { // empty file
        int errorWriting = write(cachefd, CacheManager::CACHE_LINE, CacheManager::CACHE_LINE_LENGTH);
        if (errorWriting < 0) {
          close(cachefd);
          throw system_error{errno, system_category()}; 
        }
    } else if (errorID > 0 && (strcmp(cacheID, CacheManager::CACHE_LINE) != 0)) { // the file does not start with our line
        close(cachefd);
        throw runtime_error("A file named 'Cache__DONT_TOUCH_THIS_FILE.txt' which is not a cache manager allready exists. Changed it's name and run the program again.");
    } else if (errorID < 0) { // a system error
        close(cachefd);
        throw system_error{errno, system_category()};
    }
    close(cachefd);
}

void createBeckupFile(const Operation& _operation, unsigned int index) {
    string fileName = "src/bin/cache/files/" + std::to_string(index) + "." + _operation.getOutputFileType();
    const auto cachefd = open(fileName.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw system_error{errno, system_category()};
    }
    _operation.writeToFile(fileName);
}

uint32_t getCashFileIndex() {
    ifstream cacheFile;
    cacheFile.open(CacheManager::CACHE_FILE);
    if (cacheFile.fail()) {
        throw std::system_error(errno, system_category());
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

void CacheManager::performOperation(bool isSearched /*= false*/, bool isClear /*= false*/) const {
    checkCacheFileExists();
    if (isClear) {
        if (!std::filesystem::remove_all(CACHE_DIR)) {
            throw system_error(errno, system_category());
        }
        return;
    }

    if (isSearched) {
        string search = this->search();
        if (search == "") {
             cout << "result wasn't found in cache" << endl;
        } else {
            cout << "result found in cache – saved on " << search.substr(0, CurrentTime::TIME_STRING_LENGTH) << endl;
        }
        return;
    }

    string result = search();
    if (result.compare("") != 0) {
        // first we will find the cache file that suits to the operation and copy it to our destination file
        string replace, fileName;
        unsigned int index = stoi(result.substr(result.find_last_of('|') + 1));
        fileName = CACHE_FILES_DIR_ + to_string(index) + '.' + _operation->getOutputFileType();

        _operation->writeToOutputFile(readFileContent(fileName));

        // changing the time & date
        CurrentTime ct = CurrentTime();
        replace = ct.getTime() + '|' + std::to_string(index);

        // replace the date (the whole line) in the cache file
        string cache = readFileContent(CACHE_FILE);
        cache.replace(cache.find(result), result.size(), replace);
        writeFileContent(CACHE_FILE, cache);

        return;
    }

    _operation->writeToOutputFile();

    // writes the operation line into the cache file
    string cacheCopy = "";
    if (!isSearched) {
        cacheCopy += readFileContent(CACHE_FILE);
        cacheCopy.erase(0, CACHE_LINE_LENGTH);
        string cache = CACHE_LINE + _operation->getCacheString();
        //adding the time & date
        cache += ",";
        CurrentTime ct = CurrentTime();
        cache += ct.getTime();
        unsigned int index = getCashFileIndex();
        cache += "|" + std::to_string(index);
        cache += "\n";//end of line
        cache += cacheCopy;

        writeFileContent(CACHE_FILE, cache);

        createBeckupFile(*_operation, index);
    }
}

string CacheManager::search() const {    
    ifstream cacheFile;
    cacheFile.open(CACHE_FILE);
    if (cacheFile.fail()) {
        throw std::system_error(errno, system_category());
    }

    // checks if every begining of a line is similar to the CacheString of the operation
    // if it finds the similar one it will return something to print
    string line, operationLine;
    if (_operation != nullptr) {
        operationLine = _operation->getCacheString();
    } else {
        throw runtime_error(UNKNOWN_COMMAND);
    }
    int lastToCompare = operationLine.find_last_of(',') - 1;
    getline(cacheFile, line); //the title
    while (getline(cacheFile, line)) {
        if (line.substr(0, line.find(',')).compare(operationLine.substr(0, lastToCompare)) == 0) {
            return line.substr(line.find(',') + 1);
        }
    }

    return ""; //didn't find
}

bool CacheManager::isSearch(int argc, const char* argv[]) {
    // to few arguments
    if (argc < 3) {
        return false;
    }
    return strcmp(argv[0], "cache") == 0 && strcmp(argv[1], "search") == 0;
}

bool CacheManager::isClear(int argc, const char* argv[]) {
    // only 2 arguments in this cache operation
    if (argc != 2) {
        return false;
    }
    return strcmp(argv[0], "cache") == 0 && strcmp(argv[1], "clear") == 0;
}