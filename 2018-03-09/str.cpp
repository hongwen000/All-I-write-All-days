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
    char msg1[] = "123456\0hahaha";
    char msg2[] = "sdfds\0dfsdf";
    std::string s;
    s.append(msg1, 0, 6 + 1 + 6);
    s.append(msg2, 0, 5 + 1 + 5);
    std::cout << s << std::endl;
    std::cout << s.c_str() << std::endl;
    std::cout << s.size() << std::endl;
}
