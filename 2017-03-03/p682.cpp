#include <iostream>
using namespace std;
template <typename T1, typename T2, typename T3>
T1 sum(T2 v1, T3 v2) 
{
    return v1 + v2;
}
int main()
{
    int i = 1;
    long lng = 2;
    auto val3 = sum<long long>(i, lng);
    cout << val3 << endl;
    return 0;
}

