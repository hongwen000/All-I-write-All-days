#include <iostream>
#include <ctime>
using namespace std;
class Time
{
  public:
    Time();
    Time(int  _Total_Second);
    int getHour();
    int getMinute();
    int getSecond();
    private:
    int hour;
    int minute;
    int second;
};
Time::Time()
{
int Total_Second=time(0);
int Total_Minute=Total_Second/60;
int Total_Hour=Total_Minute/60;
Time::second=Total_Second%60;
Time::minute=Total_Minute%60;
Time::hour=Total_Hour%24;
}
Time::Time(int _Total_Second)
{
int Total_Second=_Total_Second;
int Total_Minute=Total_Second/60;
int Total_Hour=Total_Minute/60;
Time::second=Total_Second%60;
Time::minute=Total_Minute%60;
Time::hour=Total_Hour%24;
}
int Time::getHour()
{
return Time::hour;
}
int Time::getMinute()
{
return Time::minute;
}
int Time::getSecond()
{
return Time::second;
}

int main()
{
    Time Current_Time;
    cout << Current_Time.getHour()<<":"<<Current_Time.getMinute()<<":"<<Current_Time.getSecond() << endl;
    return 0;
}
