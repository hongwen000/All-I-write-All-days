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


