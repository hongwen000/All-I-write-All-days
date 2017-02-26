#include <iostream>
#include <stack>

using namespace std;

int num1[200001],num2[200001];

void pre()
{
    for(int i=0;i<200001;i++)
    {
        num1[i] = 0;
        num2[i] = 0;
    }
}

int main()
{
    int n;
    while(cin >> n && n)
    {
        pre();
        int a,b;
        for(int i=0;i<n;i++)
        {
            cin >> a >> b;
            num1[a] = b;
            num2[b] = a;
        }
        stack<int> st;
        for(int i=1;i<=n*2;i++)
        {
            if(st.empty())
                st.push(i);
            else if(num1[st.top()] == i || num2[st.top()] == i)
            {
                st.pop();
            } 
            else st.push(i);
        }
        if(st.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
} 