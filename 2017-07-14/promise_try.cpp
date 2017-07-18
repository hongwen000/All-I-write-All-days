#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

std::future<int> fut;
std::promise<int> prom; // 生成一个 std::promise<int> 对象.

void print_int(std::future<int>& fut) {
    int x = fut.get(); // 获取共享状态的值.
    std::cout << "value: " << x << '\n'; // 打印 value: 10.
}

int main ()
{
    fut = prom.get_future(); // 和 future 关联.
    std::thread t(print_int, std::ref(fut)); // 将 future 交给另外一个线程t.
    std::cout << "啦啦啦啦" << std::endl;
    prom.set_value(10); // 设置共享状态的值, 此处和线程t保持同步.
    t.join();
    return 0;
}