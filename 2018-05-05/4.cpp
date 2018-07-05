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
#include "fmt/format.h"
using namespace std;

int main([[maybe_unused]]int argc, [[maybe_unused]]const char *argv[])
{
    const std::map<std::string, std::string> capitals {
        { "Poland", "Warsaw"},
        { "USA", "Washington"},
        { "France", "Paris"},
        { "UK", "London"},
        { "Germany", "Berlin"}
    };
    for(auto& [key, val] : capitals)
    {
        fmt::print("The captical of {} is {}\n", key, val);
    }
    return 0;
}
