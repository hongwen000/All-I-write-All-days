#include <iostream>
#include <ctime>
using namespace std;
class Time{
    int Hour, Minute, Second;
    public:
        Time();
        Time(int totalSeconds);
        int getHour();
        int getMinute();
        int getSecond(); 
    };
Time::Time()
{
    const time_t t = time(NULL);
    Hour = t / 3600;
    Minute = t % 3600 / 60;
    Second = t % 60;
}
Time::Time(int totalSeconds)
{
    Hour = totalSeconds / 3600;
    Minute = totalSeconds % 3600 / 60;
    Second = totalSeconds % 60;
}
int Time::getHour() {return Hour;}
int Time::getMinute() {return Minute;}
int Time::getSecond() {return Second;}
int main()
{
    Time time;
    cout << time.getHour() << endl;
    cout << time.getMinute() << endl;
    cout << time.getSecond() << endl;
    return 0;
}


