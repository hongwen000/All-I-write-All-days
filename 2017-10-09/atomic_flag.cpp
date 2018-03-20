#include <iostream>       // std::cout
#include <atomic>         // std::atomic_flag
#include <thread>         // std::thread
#include <vector>         // std::vector
#include <sstream>        // std::stringstream

std::atomic_flag lock_stream = ATOMIC_FLAG_INIT;//flag处于clear状态，没有被设置过
std::stringstream stream;

void append_number(int x) {
  while (lock_stream.test_and_set()) {}//检查并设置是个原子操作，如以前没有设置过则退出循环，
    //每个线程都等待前面一个线程将lock_stream状态清楚后跳出循环
  stream << "thread #" << x << '\n';
  lock_stream.clear();}
int main (){
  std::vector<std::thread> threads;
  for (int i=1; i<=10; ++i)
     threads.push_back(std::thread(append_number,i));
  for (auto& th : threads) th.join(); std::cout << stream.str(); return 0;
}
