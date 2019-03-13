#include <cstdio>
#include <string>
#define MAXN 1000
#define MAXC 256
using namespace std;

char s[MAXN];
bool ans[MAXC];

int main()
{
    FILE* in = fopen("in", "r");
    fscanf(in, "%s", s);
    int i = 0;
    while(s[i] != 0)
    {
        ans[s[i]] = true;
        i++;
    }
    for(int i = 0; i < MAXC; ++i)
    {
        if(ans[i])
            putchar(i);
    }
    putchar('\n');
}