#pragma once

#include <string>
#include <ctime>
#include <stdint.h>

using std::string;
using std::uint32_t;

class CurrentTime {

	string _time = "";

public:
    CurrentTime();
    string getTime() const;
};