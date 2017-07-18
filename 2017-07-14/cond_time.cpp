#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>
using namespace std;
condition_variable cv;
bool done = true;
mutex m;

void wait_loop()
{
    unique_lock<mutex> lk(m);
    if(cv.wait_for(lk, chrono::milliseconds(500)) == cv_status::timeout)
        done = false;
    lk.unlock();
}

void prepare()
{
    this_thread::sleep_for(chrono::milliseconds(499));
    cv.notify_one();
}

int main()
{
    thread t1(wait_loop);
    thread t2(prepare);
    t1.join();
    t2.join();
    unique_lock<mutex> lk(m);
    cout << done << endl;
    lk.unlock();
    return 0;
}