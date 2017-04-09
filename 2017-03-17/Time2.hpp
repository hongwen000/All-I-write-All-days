#ifndef TIME_HPP
#define TIME_HPP
#include <string>
#include <iostream>
using namespace std;
 
class Time {
    private:
        int hour;
        int minute;
        int second;
    public:
        Time(int hour = 0, int minute = 0, int second = 0);
        Time(const Time& time);
        ~Time();
        void setHour(int hour);
        void setMinute(int minute);
        void setSecond(int second);
        int getHour() const;
        int getMinute() const;
        int getSecond() const;
        string toString() const;
        bool isValid() const;
        Time after(int seconds);
        void increment();
};
#endif

