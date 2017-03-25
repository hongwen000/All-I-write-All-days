#include <cstdio>
#define PRINT_INT(s) printf(##s"=%d",s)
int main()
{
    int i = 0;
    PRINT_INT(i);
    return 0;
}
