#include <iostream>
#include <cstring>   
#include <stack>
using namespace std;
int main()
{
    stack <int> s;
    int a[200001];
    while(true)
    {
		memset(a,0,sizeof(a));
        int N;
        cin>>N;
        if(!N)
            return 0;
        for(int i=1;i<=N;i++)
        {
			int h,w;
            cin >>h>>w;
            a[h]=i;
            a[w]=i;
        }
		int up=2*N;
        for(int i=1;i<=up;i++)
        {
			int num=a[i];
			int last_num=a[up];
			if(num == last_num)
			{
				up--;
				continue;
			}
            if(s.empty())
            {
                s.push(num);
            }
            else
            {
				if(s.top()==num)
					s.pop();
				else
					s.push(num);
            }
        }
        if(s.empty())
            cout <<"Yes"<<endl;
        else
            cout <<"No"<<endl;
    }
    return 0;
}
