#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
    int mo = 1e9 + 7;
    cout << mo << endl;
    int n, q;
    cin >> n >> q;
    int ret = 0;
    int d = 1;
    for(int i = (n-q)+1; i <= n; ++i)
    {
        d *= i;
        d %= mo;
    }
    cout << d << endl;
    int dor = 1;
    for(int i = 1; i <= q; ++i)
    {
        dor *= i;
        dor %= mo;
    }
    cout << dor << endl;
    cout << "Ret" << (double)d/(double)dor;
    d = (d / dor) % mo;
    int ex = 1;
    for(int i = 0; i < n-q; ++i)
    {
        ex *= 2;
        ex %= mo;
    }
    cout << ex << endl;
    cout << ex * d << endl;
}