#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>
#include "Time.hpp"
using namespace std;

Time::Time(int _hour, int _minute, int _second) : hour(_hour), minute(_minute), second(_second) {}
Time::Time(const Time& time) {
    *this = time;
}
void Time:: setHour(int hour) {
    this->hour = hour;
}
void Time:: setMinute(int minute) {
    this->minute = minute;
}
void Time:: setSecond(int second) {
    this->second = second;
}
int Time:: getHour() const {
    return hour;
}
int Time:: getMinute() const {
    return minute;
}
int Time:: getSecond() const {
    return second;
}
string Time:: toString() const {
    stringstream ss;
    ss << setw(2) << setfill('0') << to_string(hour % 12) << ":" << setw(2) << setfill('0') << to_string(minute) << ":" << setw(2) << setfill('0') << to_string(second) << " " << (hour >= 12 ? "PM" : "AM");
    //return to_string(hour % 12) + ":" + to_string(minute) + ":" + to_string(second) + " " + (hour >= 12 ? "PM" : "AM");
    return ss.str();
}
bool Time:: isValid() const {
    return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59);
}
Time Time:: after(int seconds) {
	Time newtime(*this);
    bool addon = false;
    (newtime.second += seconds % 60) = (newtime.second >= 60 ? (addon = true, newtime.second - 60) : newtime.second);
    (newtime.minute += (seconds % 3600) / 60 + addon) = (newtime.minute >= 60 ? (addon = true, newtime.minute - 60) : (addon = false, newtime.minute));
    (newtime.hour += (seconds / 3600) % 24 + addon) = (newtime.hour >= 24 ? newtime.hour - 24 : newtime.hour);
	return newtime;
}
Time:: ~Time()
{
    cout << "Recycle time: " << toString() << endl;
}

