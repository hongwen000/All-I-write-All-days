#include <iostream>
#include <cstring>   
#include <stack>
using namespace std;

int main()
{
	int a[200001], b[200001];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    stack <int> s;
    while(true)
    {
        int N;
        cin>>N;
        if(!N)
            return 0;
        for(int i=1;i<=N;i++)
        {
            int h,w;
            cin >>h>>w;
            a[h]=i;
            b[w]=i;
        }
        for(int i=1;i<=2*N;i++)
        {
            if(s.empty())
            {
                if(a[i])
                    s.push(a[i]);
                if(b[i])
                    s.push(b[i]);
            }
            else
            {
                if(a[i]!=0&&s.top()==a[i])
                    s.pop();
                else if(a[i]!=0&&s.top()!=a[i])
                    s.push(a[i]);
                else if(b[i]!=0&&s.top()==b[i])
                    s.pop();
                else if(b[i]!=0&&s.top()!=b[i])
                    s.push(b[i]);
				else{while(1){}}
            }
        }
        if(s.empty())
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}
