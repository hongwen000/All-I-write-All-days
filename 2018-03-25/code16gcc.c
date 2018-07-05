//__asm__(".code16gcc\n");
#include "/Users/lixinrui/onedrive/Documents/大学课程/2018操作系统实验/os_lab3/test/include/defines.h"
extern int asm_func(int x, int y);

int c_func(int x, int y)
{
    asm_func(x, y);
    return 0;
}
int c_start(int x, int y)
{
    c_func(x, y);
    return 0;
}

