#include <atomic>
#include <mutex>
#include <thread>
#include <iostream>
using namespace std;
constexpr int cnt = 10000;
mutex mutA;
mutex mutB;
int A;
int B;
condition_variable notify;
atomic_bool _begin(false);
void P()
{
    while(!_begin);
    unique_lock<mutex> locA(mutA);
    for (int i = 0; i < cnt; i++) {
        
    }
    std::cout << "P Req B" << std::endl;
    unique_lock<mutex> locB(mutB);
    for (int i = 0; i < cnt; i++) {
        
    }
    locA.unlock();
    locB.unlock();
}
void Q()
{
    while(!_begin);
    unique_lock<mutex> locB(mutB);
    for (int i = 0; i < cnt; i++) {
        
    }
    std::cout << "Q Req A" << std::endl;
    unique_lock<mutex> locA(mutA);
    for (int i = 0; i < cnt; i++) {
        
    }
    locB.unlock();
    locA.unlock();
}
int main()
{
        std::thread A(P);
        std::thread B(Q);
        _begin = true;
        A.join();
        B.join();
        _begin = false;
    return 0;
}
