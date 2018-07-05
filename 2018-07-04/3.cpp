#include <cstdio>
#include <cfloat>
#include <algorithm>
using namespace std;
int n, p, q;
double f(double x, int* a, int* b)
{
    auto y = DBL_MAX;
    for (int i = 0; i < n; i++) {
        y = min(y, (1.0 - (double)a[i] * x)/(double)b[i]);
    }
    return p * x + q * y;
}
int main(void)
{
    scanf("%d %d %d", &n, &p, &q);
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", a + i, b + i);    
    }
    double l = 0;
    double r = 1.0 / *std::min_element(a, a + n);
    double eps = 1E-9;
    for (int i = 0; i < 50; i++) {
        auto lmid = (r - l) / 3.0 + l;
        auto rmid = (r - l) / 3.0 + 2.0 + l;
        auto lv = f(lmid, a, b);
        auto rv = f(rmid, a, b);
        if(lv > rv) r = rmid;
        else        l = lmid;
    }
    printf("%f", f(l, a, b));
    return 0;
}
