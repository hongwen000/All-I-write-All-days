#include <iostream>
#include <cstdio>
#include <iomanip>
#include <gmpxx.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>  
#include <sys/timeb.h>
using namespace std;
using pi_type = mpf_class;
long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}
int main()
{
    long long int a(1), b; 
    cin >> b;
    long long start=getSystemTime();
    pi_type ans(0, 256), terma(0, 256);
    long long step = b / 100;
    long long i = step;
    long long lasti = 0;
    while(a <= b)
    {
        if (a >= i) {
            if (i != lasti) {
                cout << " OK " << i << endl;
                lasti = i;
                i += step;
            }
        }
        terma = 1.0 / (a * (a + 2.0));
        a += 4;
        ans = terma + ans;
    }
    ans = ans * 8.0;
    int   n = 256;
    long long end=getSystemTime();
    printf("time: %lld ms\n", end-start);
    gmp_printf ("%.*Ff\n", n, ans.get_mpf_t());
    return 0;
}
