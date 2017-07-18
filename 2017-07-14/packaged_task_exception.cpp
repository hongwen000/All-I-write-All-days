#include <cmath>
#include <iostream>
#include <mutex>
#include <thread>
#include <future>
#include <exception>
using namespace std;
int double_exception(int i)
{
    if(i < 0)
        throw std::out_of_range("i < 0");
    else
        return static_cast<int>(sqrt(i));
}
int main()
{
    packaged_task<int(int)> pg(double_exception);
    auto ret = pg.get_future();
    thread t1(std::move(pg), 1);
    cout << ret.get() << endl;
    t1.join();
}