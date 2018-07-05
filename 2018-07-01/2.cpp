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

int main(void)
{
    mutex m[5];
    auto f = [&m](int i) {
        while(true)
        {
            printf("%d think\n", i);
            lock_guard<mutex> g1(m[i]);
            printf("%d pick up fork %d\n", i, i);
            lock_guard<mutex> g2(m[(i + 1)%5]);
            printf("%d pick up fork %d\n", i, (i + 1)%5);
            printf("%d eat\n", i);
        }
    };
    vector<thread> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(thread(f, i));
    }
    for (auto& i : v) {
        i.join();
    }
    return 0;
}
