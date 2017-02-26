#include <iostream>
#include <ctime>
#define MAX_N 100
using namespace std;
int solve(int a[])
{
    int answer=0;
   for(int i=0;i<MAX_N;i++)
   {
      for(int j=0;i<MAX_N;j++)
      {
          for(int k=0;k<MAX_N;k++)
          {
              int longest=max(a[i],max(a[j],a[k]));
              if(longest<a[i]+a[j]+a[k]-longest)
                  answer=max(answer,longest);
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
    int answer=solve(a);
    int stop_s=clock();
    cout <<answer<<endl;
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}
