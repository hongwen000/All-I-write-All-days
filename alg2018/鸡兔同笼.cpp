#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);

    if((m-2*n) % 2 || (4*n-m) %2 || m<2*n || m>4*n)
    {
        printf("No answer");
        return 0;
    }
    else
    {
        printf("%d %d", (m-2*n)/2, (4*n-m)/2);
    }
}