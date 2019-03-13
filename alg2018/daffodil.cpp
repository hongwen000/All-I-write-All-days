#include <cstdio>
#define CUB(x) x * x * x
using namespace std;

int main()
{
    for(int i = 100; i < 1000; ++i)
    {
        int A = i % 10;
        int B = (i / 10) % 10;
        int C = i / 100;
        if(i == CUB(A) + CUB(B) + CUB(C))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}