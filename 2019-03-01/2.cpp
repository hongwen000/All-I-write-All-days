#include <cstdio>
#include <string>
#define MAXN 1000
#define MAXC 256
#define BUFN 10240
using namespace std;

char s[MAXN];
char outputbuf[BUFN];
int pos = 0;

int main()
{
    FILE* in = fopen("in2", "r");
    if(!in)
    {
        printf("Can not open file");
    }
    int N;
    fscanf(in, "%d\n", &N);
    bool ans[N][MAXC];
    memset(ans, 0, N*MAXC);
    for(int i = 0; i < N; ++i)
    {
        fscanf(in, "%s", s);
        int j = 0;
        while(s[j] != 0)
        {
            ans[i][s[j]] = true;
            j++;
        }
    }
    for(int i = 0; i < N; ++i)
    {
        bool output = true;
        for(int j = 0; j < i; ++j)
        {
            bool flag = true;
            for(int k = 0; k < MAXC; ++k)
            {
                if(ans[i][k] != ans[j][k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                output = false;
                break;
            }
        }
        if(output)
        {
            for(int j = 0; j < MAXC; ++j)
            {
                if(ans[i][j])
                    outputbuf[pos++] = j;
            }
            outputbuf[pos++] = '\n';
        }
    }
    fwrite(outputbuf, pos-1, 1, stdout);
}