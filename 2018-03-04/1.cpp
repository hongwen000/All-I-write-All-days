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
    std::map<std::string, int> mp;
    auto& ref = mp["hhh"];
    ref = 1;
    std::cout << mp["hhh"] << std::endl;
}
