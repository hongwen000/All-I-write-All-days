#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <type_traits>
using namespace std;

typedef struct _DateTime {
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint8_t second;
} DateTime;

uint8_t monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void datetime_update(uint32_t time, DateTime* dt) {
	uint32_t days = (time / 86400);

	dt->year = 1970;
	dt->month = 1;
	dt->day = 1;

	while(1) { // rewrite this!
		char leap_year = (dt->year % 4) == 0;

		for(int i = 0; i < 12 ;i++) {
			uint8_t days_in_month = monthDays[i];

			if(i == 1 && leap_year) { // February of leap year
				days_in_month++;
			}

			if(days < days_in_month) {
				dt->day = days + 1;
				days = 0;
				break;
			}

			days -= days_in_month;

			dt->month++;
		}

		if(days == 0) {
			break;
		}

		dt->month = 1;
		dt->year++;
        std::cout << dt->year << std::endl;
        std::cout << days << std::endl;
	}

	uint32_t seconds = (time % 86400);

	dt->hour = seconds / 3600;
	dt->minute = (seconds % 3600) / 60;
	dt->second = (seconds % 3600) % 60;
}

tm __LIBC__TM__;

static bool is_leap_year(uint16_t year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
static int weekday(int y, int m, int d){
    return (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;  
};

struct tm* mygmtime(const time_t tp)
{
    tm* ret = & __LIBC__TM__;
    ret->tm_year = 1970;
    ret->tm_mon = 1;
    ret->tm_mday = 1;
    int day_of_mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = tp / 86400;
    while(days) 
    {
        int yday = 0;
        bool is_leap = is_leap_year(ret->tm_year);
        for(int i = 0; i < 12; ++i)
        {
            int day_this_mon = (i == 1 && is_leap)
                ? 29 : day_of_mon[i];
            if(days < day_this_mon)
            {
                ret->tm_mday = days + 1;
                ret->tm_yday = yday + 1;
                days = 0;
                break;
            }
            yday += day_this_mon;
            days -= day_this_mon;
            ret->tm_mon++;
        }
        if(!days) break;
        ret->tm_year++;
        //std::cout << ret->tm_year << std::endl;
        //std::cout << days << std::endl;
        ret->tm_mon = 1;
    }
    ret->tm_sec = tp % 60;
    ret->tm_min = (tp % 3600) / 60;
    ret->tm_hour = (tp / 3600) % 24;
    ret->tm_wday = weekday(ret->tm_year, ret->tm_mon, ret->tm_mday);
    return ret;
}
int main() {

    const char* sys_internal_time_str = "2018 4 13 2 17 0";
    int sys_sec = 0;
    int sys_minute = 0;
    int sys_hour = 0;
    int sys_day = 0;
    int sys_month = 0;
    int sys_year;
    sscanf(sys_internal_time_str,"%d %d %d %d %d %d", 
            &sys_year, &sys_month, &sys_day,
            &sys_hour, &sys_minute, &sys_sec);
    uint32_t ts = 0;
    uint8_t cnt_non_leap = 0;
    uint8_t cnt_leap = 0;
    for( uint16_t i = 1970; i < sys_year; i++ )
    {
        is_leap_year(i) ? cnt_leap++ : cnt_non_leap++;
    }
    int ddd = (cnt_non_leap*365) + (cnt_leap*366);
    std::cout << ddd << std::endl;
    ts += (ddd) * 86400;
    int day_of_mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int cnt = 0;
    for(uint8_t i = 0; i < (sys_month - 1); i++ )
    { 
        cout << ((i == 1 && is_leap_year(sys_year)) ? 
            (day_of_mon[i]) : (29)) << std::endl;
    }
    std::cout << cnt << std::endl;
    std::cout << ts/86400 << std::endl;
    ts += (sys_day-1) * 86400; 
    ts += sys_hour * 3600;
    ts += sys_minute * 60;
    ts += sys_sec;

    auto tp = mygmtime(ts);

    printf("%d/%d/%d-%d:%d:%d", tp->tm_year, tp->tm_mon, tp->tm_mday,
            tp->tm_hour, tp->tm_min, tp->tm_sec);

}
