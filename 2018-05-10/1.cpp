#include <iostream>
void vga_putchar(int c, int color, int x, int y)
{
    uint16_t * pVRAM = (uint16_t *) 0xB8000;
    pVRAM = pVRAM + (x * 80 + y) ;
    *pVRAM = c | (color << 8);
}

int main()
{
    vga_putchar('a', 0x07, 0, 0);
}
