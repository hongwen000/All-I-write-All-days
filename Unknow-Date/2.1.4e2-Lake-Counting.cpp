#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_M 100
int DFS1(char **yard)
{
    return 0;
}
int DFS2(int i, int j, int N, int M, char (*yard)[100])
    {
        yard[i][j]='.';
        for(int dx=-1;dx<=1;dx++)
        {
            for(int dy=-1;dy<=1;dy++)
            {
                int new_i=i+dx;
                int new_j=j+dy;
                if(new_i>=0 && new_i<N && new_i>=0 && new_j<M && yard[new_i][new_j] == 'W')
                    DFS2(new_i,new_j,N,M,yard);
            }
        }
        return 1;
    }
int main()
{
    int ans=0;
    int N,M;
    cin >>N>>M;
    char yard[MAX_N][MAX_M];//why plus 1 
    char yard2[MAX_N]="abcd";
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin >>yard[i][j];
        }
    }
    DFS1(yard);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(yard[i][j]=='W')
            {
                DFS2(i,j,N,M,yard);
                ans++;
            }
        }
    }
    cout << ans<<endl;
    cout <<yard<<endl;
    cout <<yard2<<endl;
    return 0;
}

