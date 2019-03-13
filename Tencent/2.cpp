#include <iostream>
#include <cstdint>
using namespace std;
inline int ret(int m, int n)
{
    return (n-m)/2  + 1;
}
int main()
{
    int N;
    cin >> N;
    int m, n;
    while(N--)
    {
        scanf("%d%d", &m, &n);
        if(m%2 == 1 && n%2 == 0)
        {
            printf("%d\n", ret(m,n));
        }
        else if(m%2 == 0 && n%2 == 0)
        {
            printf("%d\n", ret(m-1,n) + (m-1));
        }
        else if(m%2 == 1 && n%2 == 1)
        {
            printf("%d\n", ret(m,n+1) - (n+1));
        }
        else
        {
            printf("%d\n", ret(m-1,n+1) +(m-1) - (n+1));
        }
    }
}