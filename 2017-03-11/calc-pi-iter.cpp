#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
using pi_type = long double;
int main()
{
    long long int a(1), b; 
    cin >> b;
    pi_type ans(0);
    while(a <= b)
    {
        pi_type terma = 1.0 / ( a * ( a + 2.0)); 
        a += 4;
        ans = terma + ans;
    }
    printf("%Lf\n", 8.0 * ans);
    cout << fixed << setprecision(40) << 8.0 * ans << endl;
    return 0;
}
