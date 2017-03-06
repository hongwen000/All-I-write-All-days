#include <iostream>
#include <algorithm>
#define MAX_N 1000
using namespace std;
int main()
{
    int L,n,x[MAX_N];
    cin >>L;
    cin >>n;
    bool flag=false;
    int maxx=0,minn=0;
    for(int i=0;i<n;i++)
    {
        cin >> x[i];
        int otherside=L-x[i];
        if(!flag)
        {
            minn=x[i];
            flag=true;
        }
        maxx=max(maxx,max(x[i],otherside));
        minn=min(minn,min(x[i],otherside));
    }
    cout <<"min="<<minn<<endl;
    cout <<"max="<<maxx<<endl;
    return 0;
}
