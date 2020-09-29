#include "CurrentTime.hpp"

using std::string;
using std::uint32_t;

/**
 * @brief Get the String object.
 * 
 * note: excepected to get one or to digits number
 * and to return string with to digits (1 -> 01);
 * 
 * @param num the number to get string from.
 * @return string 
 */
string getString(int num) {
    string s = std::to_string(num);

    while(s.length() < 2) {
        s = "0" + s;
    }

    return s;
}

string cache::timeCounter::getTime() { 
    //current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);

    //calculating the time & date to string
   string time = "";
   time += getString(ltm->tm_mday);
   time += "/";
   time += getString(ltm->tm_mon + 1);
   time += "/";
   time += std::to_string(ltm->tm_year).substr(1, 2); //the year is from 1900
   time += " ";
   time += getString(ltm->tm_hour);
   time += ":";
   time += getString(ltm->tm_min);

   return time;
 }
