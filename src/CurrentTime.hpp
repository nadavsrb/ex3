#pragma once

#include <string>
#include <ctime>
#include <stdint.h>

using std::string;
using std::uint32_t;

class CurrentTime {
	string _time = "";

public:
    static const uint32_t TIME_STRING_LENGTH = 14;

    CurrentTime();
    string getTime() const;
};