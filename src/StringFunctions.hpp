#include <string>

using namespace std;

    
string copyToString(const char *charArray) {
    string str = "";
    for (unsigned int i = 0; charArray[i] != '\0'; ++i) {
        str += charArray[i];
    }

    return str;
}

bool typed(const string& fileName, const string& type) {
    return fileName.substr(fileName.find_last_of('.') + 1).compare(type) == 0;
}