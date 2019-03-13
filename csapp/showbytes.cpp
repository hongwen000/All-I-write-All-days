#include "stdio.h"
#include "cstring"
#include "type_traits"
using namespace std;

template<typename T>
void show_bytes(T x, size_t len = -1)
{
    if(len == -1) len = sizeof(T);
    auto p = (unsigned char*) &x;
    for(size_t i = 0; i < len; ++i)
        printf(" %.2x", p[i]);
    printf("\n");
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_bytes(ival);
    show_bytes(fval);
    show_bytes(pval);
}

int main()
{
    auto s = "abcde";
    show_bytes(s, strlen(s));
}
