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
int main(int argc, const char *argv[])
{
    mutex A, B;

    auto f1 = [&A, &B](){
        A.lock();
        std::this_thread::sleep_for(chrono::seconds(1));
        B.lock();
        B.unlock();
        A.unlock();
    };
    auto f2 = [&A, &B](){
        B.lock();
        std::this_thread::sleep_for(chrono::seconds(1));
        A.lock();
        A.unlock();
        B.unlock();
    };
    thread t1(f1);
    thread t2(f2);
    t1.join();
    t2.join();
    return 0;
}
