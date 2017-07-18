#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <exception>
using namespace std;

void foo(future<int>& fut)
{
    auto x = fut.get();
    cout << x << endl;
}
int main()
{
    promise<int> prom;
    auto fut = prom.get_future();
    thread t(foo, ref(fut));
    prom.set_exception(make_exception_ptr(std::runtime_error{"oh no"}));
    t.join();
}