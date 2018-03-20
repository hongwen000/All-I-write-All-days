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
using namespace std;
#include <gtest/gtest.h>

template<typename T, typename K>
class X {

};

template<typename T>
class Y {

};

template<typename T>
void f(X<Y<T>,Y<T>>);

void g()
{
    f(X<Y<int>,Y<char>>());
}
