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
    std::cout << "Info: In watcher send func [" << (unsigned)mes.stage() << "/" << (unsigned)mes.total() <<
                "] " << mes.md5() << ":" << mes.body() << std::endl;
    chat_message new_mes(mes.data(), mes.length());
    std::cout << "Info: In watcher send func [" << (unsigned)mes.stage() << "/" << (unsigned)mes.total() <<
                "] " << mes.md5() << ":" << mes.body() << std::endl;
}
