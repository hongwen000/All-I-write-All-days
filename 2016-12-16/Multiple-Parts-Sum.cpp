#include <cstdio>
#define MAX_N 100
#define MAX_K 100000
int a[MAX_N + 1];
int m[MAX_N + 1];
int f[MAX_N + 1][MAX_K + 1];
int main()
{
    int n;
    int K;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }
    scanf("%d", &K);
    f[0][0]=true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= K; j++){
            for(int q = 0; q <= m[i] && q * a[i] <= j; q++){
                f[i+1][j] |= f[i][j - q * a[i]];
            }
        }
    }
    if(f[n][K])
        printf("Yes\n");
    else
        printf("No\n");
}
