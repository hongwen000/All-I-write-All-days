#include <stdio.h>
#include <math.h>
int main()
{
    int n, m;
    scanf("%d", &n);
    int a[n];
    for(int t = pow(10.0, n-1); t < pow(10.0, n); ++t)
    {
        m = t;
        int s = 0;
        for(int i = 0; i < n; ++i)
        {
            a[i] = m % 10;
            m = m / 10;
            s = pow(a[i], n) + s;
        }
        if(s == t)
            printf("%d\n", t);
    }
}