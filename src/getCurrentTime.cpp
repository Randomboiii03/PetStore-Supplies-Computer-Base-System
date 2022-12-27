#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "petshop.h"

using namespace std;

string getCurrentTime() {
    // get current time
    time_t t = time(nullptr);
    tm tm = *localtime(&t);

    // create a stringstream to hold the formatted time
    stringstream ss;

    // format the time using put_time and write it to the stringstream
    ss << put_time(&tm, "%Y-%m-%d %H:%M:%S");

    // extract the formatted time from the stringstream as a string
    string dateTime = ss.str();

    return dateTime;
}