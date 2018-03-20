#include "chat_message.hpp"
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
#include <gtest/gtest.h>
int main()
{
    string s = "global";
    chat_message mes(4, 0, Thilo::md5("hhh"), "2018-03-18 15:09:12.003478", s);
    std::cout << "Info:Send [" << (unsigned)mes.stage() << "/" << (unsigned)mes.total() <<
                "] " << mes.md5() << ":" << mes.body() << std::endl;
    std::cout << "Time is " << mes.time_stamp() << std::endl;
    chat_message new_mes(mes.data(), mes.length());
    std::cout << "Info:recv [" << (unsigned)mes.stage() << "/" << (unsigned)mes.total() <<
                "] " << mes.md5() << ":" << mes.body() << std::endl;
    std::cout << "Time is " << new_mes.time_stamp() << std::endl;
    
}
