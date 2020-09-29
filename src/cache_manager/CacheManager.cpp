#include "CacheManager.hpp"

using namespace cache;

CacheManager::CacheManager(std::shared_ptr<cache::operation::Operation> op) : m_operation(op) {}

/**
 * @brief throws an error if the user added a file named like our cache file.
 * if the cache file does not exist the function creates a new one.
 */
void checkCacheFileExists() {
    //make the dir cache
    if (!std::filesystem::exists(CacheManager::CACHE_DIR) && mkdir(CacheManager::CACHE_DIR, 0777) < 0) {
        throw std::system_error{errno, std::system_category()};
    }
    //make the dir for the cache files
    if (!std::filesystem::exists(CacheManager::CACHE_FILES_DIR) && mkdir(CacheManager::CACHE_FILES_DIR, 0777) < 0) {
        throw std::system_error{errno, std::system_category()};
    }

    // opening the cache file
    const auto cachefd = open(CacheManager::CACHE_FILE, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw std::system_error{errno, std::system_category()};
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
          throw std::system_error{errno, std::system_category()}; 
        }
    } else if (errorID > 0 && (strcmp(cacheID, CacheManager::CACHE_LINE) != 0)) { // the file does not start with our line
        close(cachefd);
        throw std::runtime_error("A file named 'Cache__DONT_TOUCH_THIS_FILE.txt' which is not a cache manager allready exists. Changed it's name and run the program again.");
    } else if (errorID < 0) { // a system error
        close(cachefd);
        throw std::system_error{errno, std::system_category()};
    }
    close(cachefd);
}

/**
 * @brief Creates a Beckup File.
 * for an operation.
 * 
 * @param _operation the operation to make beckup file for.
 * @param index the index of the beckup file.
 */
void createBeckupFile(const cache::operation::Operation& _operation, const unsigned int index) {
    //gets the files name.
    std::string fileName = CACHE_FILES_DIR_ + std::to_string(index) + "." + _operation.getOutputFileType();

    //opening (& creating if needed) the file.
    const auto cachefd = open(fileName.c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (cachefd < 0) {
        throw std::system_error{errno, std::system_category()};
    }

    //try to write the beckupfile.
    try{
        _operation.writeToFile(fileName);
    } catch(const std::exception& e) {
        close(cachefd);
        throw e;
    }

    close(cachefd);
}

/**
 * @brief Get the Cash File Index for the beckup file.
 * 
 * @return uint32_t the index for the beckup file.
 */
uint32_t getCashFileIndex() {
    //opens the catche file
    std::ifstream cacheFile;
    cacheFile.open(CacheManager::CACHE_FILE);
    if (cacheFile.fail()) {
        throw std::system_error(errno, std::system_category());
    }

    //helping varible
    std::string line;

    //if not operation was done yet
    getline(cacheFile, line); //the title
    if (cacheFile.eof()) {
        cacheFile.close();
        return 0;
    }

    //gets the next index
    getline(cacheFile, line);
    cacheFile.close();
    return std::stoi(line.substr(line.find("|") + 1)) + 1;
}

void CacheManager::performOperation(bool isSearched /*= false*/, bool isClear /*= false*/) const {
    //chcking if the catch file exists & creating it if neede.
    checkCacheFileExists();

    //if clear operation
    if (isClear) {
        if (!std::filesystem::remove_all(CACHE_DIR)) {
            throw std::system_error(errno, std::system_category());
        }
        return;
    }

    //if search operation
    if (isSearched) {
        std::string search = this->search();
        if (search == "") {
            std::cout << "result wasn't found in cache" << std::endl;
        } else {
            std::cout << "result found in cache – saved on " << search.substr(0, timeCounter::TIME_STRING_LENGTH) << std::endl;
        }
        return;
    }

    //searching for the operatin in the cache file. 
    std::string result = search();

    //if found the operation
    if (result.compare("") != 0) {
        // first we will find the cache file that suits to the operation and copy it to our destination file
        std::string replace, fileName;
        unsigned int index = stoi(result.substr(result.find_last_of('|') + 1));
        fileName = CACHE_FILES_DIR_ + std::to_string(index) + '.' + m_operation->getOutputFileType();

        //writing the content from the beckup file to the output file.
        m_operation->writeToOutputFile(files::readFileContent(fileName));

        return;
    }

    //if the operation not in cache file.

    //writing the result to the output operation.
    m_operation->writeToOutputFile();

    // writes the operation line into the cache file
    std::string cacheCopy = "";
    if (!isSearched) {
        cacheCopy += files::readFileContent(CACHE_FILE);
        cacheCopy.erase(0, CACHE_LINE_LENGTH);
        std::string cache = CACHE_LINE + m_operation->getCacheString();
        //adding the time & date
        cache += ",";
        cache += cache::timeCounter::getTime();

        //adding the beckup file.
        unsigned int index = getCashFileIndex();
        cache += "|" + std::to_string(index);
        cache += "\n";//end of line

        //adding the other cache
        cache += cacheCopy;

        files::writeFileContent(CACHE_FILE, cache);

        createBeckupFile(*m_operation, index);
    }
}

std::string CacheManager::search() const {   
    //opens the catch file 
    std::ifstream cacheFile;
    cacheFile.open(CACHE_FILE);
    if (cacheFile.fail()) {
        throw std::system_error(errno, std::system_category());
    }

    //exception
    std::string line, operationLine;
    if (m_operation != nullptr) {
        operationLine = m_operation->getCacheString();
    } else {
        cacheFile.close();
        throw std::runtime_error(UNKNOWN_COMMAND);
    }

    // checks if every begining of a line is similar to the CacheString of the operation
    // if it finds the similar one it will return something to print
    int lastToCompare = operationLine.find_last_of(',') - 1;
    getline(cacheFile, line); //the title
    while (getline(cacheFile, line)) {
        if (line.substr(0, line.find(',')).compare(operationLine.substr(0, lastToCompare)) == 0) {
            cacheFile.close();
            return line.substr(line.find(',') + 1);
        }
    }

    cacheFile.close();
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