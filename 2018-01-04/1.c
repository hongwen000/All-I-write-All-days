#include <stdio.h>
double fun(int n)
{
    int i, k;
    double s, t;
    s = 0;
    k = 1;
    for(i = 1; i <= n; i++) {
        t = i;
        s = s + k * (2 * i - 1) * (2 * i - 1) / (t * t);
        k = k * i;
    }
    return s;
}

int main()
{
    int n = -1;
    while(n < 0) {
        scanf("%d", &n);
    }
    double ans = fun(n);
    printf("%f", ans);
}
