#include <iostream>
#include <random>
#include <numeric>
#include <chrono>
using namespace std;
double sub(double a, double b, long cycle)
{
    constexpr double l = -1000;
    constexpr double h = 1000;
    long count_in = 0;
    long count = 0;
    long length = h - l;
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count();
    std::mt19937 e(seed);
    std::uniform_real_distribution u(l, h);
    for(; count < cycle; ++count) {
        double r = u(e);
        if(r >= a && r <= b) {
            count_in++;
        }
    }
    cout << count_in << endl;
    cout << length << endl;
    return length * (static_cast<double>(count_in) / static_cast<double>(count));
}
int main()
{
    cout << sub(60, 183, 2000000) << endl;
}
