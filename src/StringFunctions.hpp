#include <string>

using namespace std;

/**
 * @brief Copy a string from char* to std::string.
 * 
 * @param charArray - the string in char*.
 * @return string 
 */
string copyToString(const char *charArray);
/**
 * @brief Checks if a file is typed "type".
 * 
 * @param fileName - the name if the file.
 * @param type - the type we are checking.
 * @return true 
 * @return false 
 */
bool typed(const string& fileName, const string& type);