#include <iostream>
#include <algorithm>
#include <chrono>
#include <sys/time.h>
#define COE 1000000 
#define MAX_N 10000
#include <ctime>
#include <thread>
#include <cmath>
using namespace std;
int conversion(struct timeval tmp_time)    
{ 
    return tmp_time.tv_sec*COE+tmp_time.tv_usec;        
} 
bool isPrime(int n)
{
    int limit=sqrt(n);
    for(int i=2;i<=limit;i++)
        if(n%i==0)
            return false;
    return true;
}
bool PrimeTable[MAX_N+1];
int perm[MAX_N+1];
int used
int main()
{
    //struct timeval start_point,end_point; 
    //gettimeofday(&start_point,NULL); 
    for(int i=0;i<10001;i++)
        PrimeTable[i]=isPrime(i);
    int m,n,d;
    while(true)
    {
        bool noPermFound=true;
        cin >>m>>n>>d;
        if(m==0&&n==0&&d==0)
            return 0;
        for(int i=0;i<n-m+1;i++)
        {
            perm[i]=m+i;
        }
        do{
            bool thisPermFail=false;
            for(int dn=2;dn<=d;dn++)
            {
                if(thisPermFail)
                    break;
                for(int p=0;p<=n-m+1-dn;p++)
                {
                    int sum=0;
                    for(int i=0;i<dn;i++)
                        sum+=perm[p+i];
                    if(PrimeTable[sum]==true)
                    {
                        thisPermFail=true;
                        break;
                    }
                }
            }
            if(thisPermFail)
			{
				/*for(int i=0;i<n-m+1;i++)
				{
					cout << perm[i] << " ";
				}
				cout <<"Fail"<<endl;*/
				continue;

			}
            else
            {
                cout <<perm[0];
                for(int i=1;i<n-m+1;i++)
                    cout<<"," <<perm[i];
                cout <<endl;
                noPermFound=false;
                break;
            }
        }while(next_permutation(perm,perm+n-m+1));
        if(noPermFound)
            cout <<"No anti-prime sequence exists."<<endl;
    }
    //gettimeofday(&end_point,NULL); 
    //cout <<"Time taken: " << (double)(conversion(end_point)-conversion(start_point))/COE<<endl;
    return 0;
}

