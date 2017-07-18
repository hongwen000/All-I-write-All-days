#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <exception>
using namespace std;
promise<int> prom;
using future_type = decltype(prom.get_future().share());
void foo(future_type fut)
{
    auto x = fut.get();
    cout << x << endl;
}
int main()
{
    vector<future_type> futs;
    vector<thread> ths;
    auto sf = prom.get_future().share();
    for(int i = 0; i < 10; ++i)
    {
        ths.push_back(thread(foo, sf));
    }    
    prom.set_value(1);
    for_each(ths.begin(), ths.end(), mem_fn(&thread::join));
    return 0;
}