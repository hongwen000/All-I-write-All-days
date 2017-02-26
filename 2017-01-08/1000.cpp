#include <stdio.h>
int main()
{
    int x = 1, y = 3, z = 4;
    unsigned int i = 0x00646c72;
    printf("H%x Wo%s\n", 57616, &i);
    printf("x=%d y=%d\n", 3);
    return 0;
}
