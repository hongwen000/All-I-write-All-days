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

int addition(int x, int y, int* cnt = nullptr)
{
    string sx = to_string(x);
    string sy = to_string(y);
    if(sx.length() > sy.length())
        swap(sx, sy);
    size_t len = max(sx.length(), sy.length());
    for(size_t i = sx.length(); i < len; ++i)
        sx = '0' + sx;
    string ans;
    int carry = 0;
    size_t i = 0;
    for(; i < len; ++i)
    {
        int nx = sx[len - i - 1] - '0';     //最低位
        int ny = sy[len - i - 1] - '0';
        int n  = nx + ny + carry;           //最低位以及进位三个数相加
        if(cnt) *cnt  += 2;
        carry  = n / 10;                    //更新进位
        n      = n % 10;                    
        char c = n + '0';
        ans    = c + ans;
    }
    ans = (carry) ? ((cnt) ? (*cnt)++ : *cnt, '1' + ans) : ans;
    return stoi(ans);
}

int multiply(int x, int y, int* cnt = nullptr)
{
    

}

int main()
{
    int cnt = 0;
    std::cout << addition(11091,90009, &cnt) << std::endl;
    std::cout << cnt << std::endl;
}
