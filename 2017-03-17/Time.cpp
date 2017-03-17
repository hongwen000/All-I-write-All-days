#include "Time.hpp"
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
    return to_string(hour % 12) + ":" + to_string(minute) + ":" + to_string(second) + " " + (hour >= 12 ? "PM" : "AM");
}
bool Time:: isValid() const {
    return (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59);
}
Time Time:: after(int seconds) {
    hour += seconds / 3600;
    minute += seconds % 3600 / 60;
    second += seconds % 60;
    hour %= 24;
}
Time:: ~Time()
{
    cout << "Recycle time: " << toString() << endl;
}

