#include <iostream>
using namespace std;
#define INF 1000000
int min(const int a, const int b)
{
    return a<b?a:b;
}
int getMultiplications(int dim, int dimensions[])
{
    int m[dim+1][dim+1];
    for(int i=0;i<dim+1;i++)
    {
        for(int j=0;j<dim+1;j++)
        {
            if(i==j)
                m[i][j]=0;
            else
                m[i][j]=INF;
        }
    }
    for(int l=2;l<dim+1;l++)
    {
        for(int i=1;i<dim+1-l+1;i++)
        {
            int j=i+l-1;
            for(int k=i;k<=j;k++)
            {
               int tmp=m[i][k]+m[k+1][j]+dimensions[i-1]*dimensions[k]*dimensions[j];
               m[i][j]=min(tmp,m[i][j]);
            }
        }
    }
    return m[1][dim];
}
int main() { 
    int dimensions[10]; 
    for (int i = 0; i < 10; ++ i) { 
        cin >> dimensions[i]; 
     } 
     cout << getMultiplications(9, dimensions); 
}
