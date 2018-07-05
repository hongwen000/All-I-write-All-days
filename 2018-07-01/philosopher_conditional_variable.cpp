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
#include <condition_variable>
std::atomic_bool in_monitor = false;
class Mycv {
    std::atomic_int q = 0;
    std::condition_variable cv;
public:
    bool empty() {
        return (q == 0);
    }
    void wait( std::unique_lock<std::mutex>& lock )
    {
        in_monitor = false;
        cv.wait(lock);
        q++;
    }
    void notify_one() noexcept
    {
        in_monitor = false;
        cv.notify_one();
        q--;
    }
};

using namespace std;
Mycv cv[5];
mutex m[5];
atomic_bool ready[5];
void get_fork(int i)
{
    int left = i;
    int right = (i + 1) % 5;    
    if(!ready[left])
    {
        unique_lock<mutex> lk(m[i]);
        cv[left].wait(lk);
    }
    ready[left] = false;
    printf("%d get fork %d\n", i, left);
    if(!ready[right])
    {
        unique_lock<mutex> lk(m[i]);
        cv[right].wait(lk);
    }
    ready[right] = false;
    printf("%d get fork %d\n", i, right);
}
void release_fork(int i)
{
    int left = i;
    int right = (i + 1) % 5;    
    if(cv[left].empty())
    {
        ready[left] = true;
    }
    else
    {
        cv[left].notify_one();
    }
    if(cv[right].empty())
    {
        ready[right] = true;
    }
    else
    {
        cv[right].notify_one();
    }
}
int main(void)
{
    for(int i = 0; i < 5; ++i)
        ready[i] = true;
    auto f = [](int i) {
        while(true)
        {
            printf("%d think\n", i);
            get_fork(i);
            printf("%d pick up fork %d\n", i, i);
            printf("%d pick up fork %d\n", i, (i + 1)%5);
            release_fork(i);
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
