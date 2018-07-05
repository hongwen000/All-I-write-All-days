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

uint8_t sys_internal_second = 0;
uint8_t sys_internal_minute = 0;
uint8_t sys_internal_hour = 0;
uint8_t sys_internal_day = 12;
uint8_t sys_internal_month = 4;
uint16_t sys_internal_year = 2018;

static bool is_leap_year(uint16_t year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

uint32_t sys_get_timestamp()
{
    uint32_t ts = 0;
    uint8_t cnt_non_leap = 0;
    uint8_t cnt_leap = 0;
    for( uint16_t i = 1970; i < sys_internal_year; i++ )
    {
        is_leap_year(i) ? cnt_leap++ : cnt_non_leap++;
    }
    ts += ((cnt_non_leap*365) + (cnt_leap*366)) * 86400;
    int days_per_month[2][12] = {
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };
    int idx = is_leap_year(sys_internal_year) ? 1 : 0;
    for(uint8_t i = 0; i < (sys_internal_month - 1); i++ )
    { 
        ts += days_per_month[idx][i] * 86400;
    }
    ts += (sys_internal_day-1) * 86400; 
    ts += sys_internal_hour * 3600;
    ts += sys_internal_minute * 60;
    ts += sys_internal_second;
    return ts;
}
int main()
{
    std::cout << sys_get_timestamp() << std::endl;
    return 0;
}
