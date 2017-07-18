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
    auto futu = async(double_exception, 9);
    auto ret = futu.get();
    cout << ret << endl;
}