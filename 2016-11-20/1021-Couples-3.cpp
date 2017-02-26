#include <iostream>
#include <stack>
using namespace std;
int a[200001],b[200001];
void pre()
{
	for(int i=0;i<200001;i++)
    {
        a[i] = 0;
        b[i] = 0;
    }	
}
int main()
{
    int N;
    while(cin>>N&&N)
    {
		pre();
		int h,w;
        for(int i=0;i<N;i++)
        {
            cin >>h>>w;
            a[h]=w;
            b[w]=h;
        }
		stack <int> s;
        for(int i=1;i<=2*N;i++)
        {
            if(s.empty())
                s.push(i);
            else if(s.top()==a[i] || s.top()==b[i])
					s.pop();
			else
				s.push(i);
        }
        if(s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
