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

template<typename T>
void showbit(const T& v)
{
    auto len = sizeof(T);
    auto start = (unsigned char*)(&v);
    for(size_t i = 0; i < len; ++i)
        printf("%.2x", start[i]);
    printf("\n");
}

int main()
{
    float a = 0.1;
    showbit(a);
}
