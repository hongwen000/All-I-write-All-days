#include <iostream>
#include <vector>
#include <string>
using namespace std;
int min(const int a, const int b)
{
    return a<b?a:b;
}
int LCS(string text1, string text2)
{
    int V=min(text1.length(),text2.length());
    int N=text1.length()+text2.length()-V;
    vector<vector<int>>f(V+1,vector<int>(N+1));
    for(auto i:f)
        for(auto j:i)
            j=0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(text1[i]==text2[j])
                f[i+1][j+1]=f[i][j]+1;
            else
                f[i+1][j+1]=max(f[i][j+1],f[i+1][j]);
        }
    }
    return f[V][N];
}
 
#include <iostream> 
using namespace std; 
 
int main() { 
        char text1[100]; 
            char text2[100]; 
                cin >> text1; 
                    cin >> text2; 
                         
                        cout << LCS(text1, text2); 
} 
