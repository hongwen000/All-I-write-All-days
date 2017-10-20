#include <cstdio>
#include <cstring>
using namespace std;
char W[1000000];
char T[1000000];
int  next[1000000];
int count; int m, n;
void buildNext() {
    int j = 0, t = -1;
    next[0] = -1;
    while(j < m) { //这里是修改的重点，next[m]是有定义的
        if(t < 0 || W[t] == W[j]) {
            ++j;
            ++t;
            next[j] = (W[t] == W[j] ? next[t] : t);
        } else {
            t = next[t];
        }
    }
}

void kmp(){
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(j < 0 || W[j] == T[i]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if(j >= m) {
            //printf("\n i = %d \n", i);
            ++count;
            //printf("j is %d, next[j] is %d\n", j, next[j]);
            j = next[j];//这里是修改的重点2
        }
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%s", W);
        scanf("%s", T);
        m = strlen(W);
        n = strlen(T);
        buildNext();
        count = 0;
        kmp();
        printf("%d\n", count);
    }
}
