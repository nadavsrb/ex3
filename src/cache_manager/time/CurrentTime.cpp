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

cache::timeCounter::CurrentTime::CurrentTime(){
    //current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);

    //calculating the time & date to string
   m_time += getString(ltm->tm_mday);
   m_time += "/";
   m_time += getString(ltm->tm_mon + 1);
   m_time += "/";
   m_time += std::to_string(ltm->tm_year).substr(1, 2); //the year is from 1900
   m_time += " ";
   m_time += getString(ltm->tm_hour);
   m_time += ":";
   m_time += getString(ltm->tm_min);
}

string cache::timeCounter::CurrentTime::getTime() const{ return m_time; }