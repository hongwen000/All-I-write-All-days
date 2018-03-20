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
    std::cout << MD5_DIGEST_LENGTH << std::endl;
    chat_message mes(4, 0, "1234567890123456", s);
    std::cout << (unsigned)mes.total() << std::endl;
    std::cout << (unsigned)mes.stage() << std::endl;
    std::cout << mes.md5() << std::endl;
    std::cout << mes.body() << std::endl;
    chat_message new_mes(mes);
    std::cout << (unsigned)new_mes.total() << std::endl;
    std::cout << (unsigned)new_mes.stage() << std::endl;
    std::cout << new_mes.md5() << std::endl;
    std::cout << new_mes.body() << std::endl;
}
