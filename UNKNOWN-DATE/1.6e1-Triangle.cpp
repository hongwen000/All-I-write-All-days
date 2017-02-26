#include <iostream>
#include <ctime>
#define MAX_N 10000
using namespace std;
int solve(int a[],int n)
{
    int answer=0;
   for(int i=0;i<n;i++)
   {
      for(int j=i+1;j<n;j++)
      {
          for(int k=j+1;k<n;k++)
          {
              int len=a[i]+a[j]+a[k];
              int longest=max(a[i],max(a[j],a[k]));
              if(longest<len-longest)
              {
                  answer=max(answer,len);
              }
           }
      }
   }
   return answer;
}
int main()
{
    int n,a[MAX_N];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int start_s=clock();
    int answer=solve(a,n);
    int stop_s=clock();
    cout <<answer<<endl;
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}
