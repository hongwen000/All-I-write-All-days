#include <stdio.h>

int backplus(int *a) {
    int b = *a;
    *a = *a + 1;
    return b;
}

int frontplus(int *a) {
    *a = *a + 1;
    return *a;
}

int main()
{
    int a = 0, b = 0;
    printf("value of expression \"a++\" is %d, it is equal to backplus(&b), which value is %d",
            a++, backplus(&b));
    printf("\n");
    printf("value of expression \"++a\" is %d, it is equal to frontplus(&b), which value is %d",
            ++a, frontplus(&b));
    return 0;
}
