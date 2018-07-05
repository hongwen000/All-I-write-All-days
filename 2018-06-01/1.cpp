#include <thread>
#include <cmath>
#include <chrono>
int main()
{
    int alpha = 10000;
    unsigned long n = 0;
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::nanoseconds((int)(alpha * std::sin(n++))));
    }
}

