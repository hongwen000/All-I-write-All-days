#include <functional>
#include <iostream>
using namespace std;
template <class T> int compare(const T& v1, const T& v2)
{
    if(less<T>() (v1, v2)) return -1;
    if(less<T>() (v1, v2)) return 1;
    return 0;
}
int main()
{
   compare("hi", "OK");
    return 0;
}
