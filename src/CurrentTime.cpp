#include "CurrentTime.hpp"

string getString(int num) {
    string s = std::to_string(num);

    while(s.length() < 2) {
        s = "0" + s;
    }

    return s;
}

CurrentTime::CurrentTime(){
    // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);


   _time += getString(ltm->tm_mday);
   _time += "/";
   _time += getString(ltm->tm_mon + 1);
   _time += "/";
   _time += std::to_string(ltm->tm_year).substr(1, 2); //the year is from 1900
   _time += " ";
   _time += getString(ltm->tm_hour);
   _time += ":";
   _time += getString(ltm->tm_min);
}

string CurrentTime::getTime() const{
    return _time;
}