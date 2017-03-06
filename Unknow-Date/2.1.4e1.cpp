#include <iostream>
#define MAX_SIZE 100
bool solve(int i,int n, int *a, int k)
{
	if(n-i==0)
	{
		return false;
	}
	else
	{
		int leftk=k-a[i];
		if(leftk==0)
			return true;
		else
			return	solve(i+1,n,a,leftk) || solve(i+1,n,a,k);
		
	}
}
using namespace std;
int main()
{
	int n;
	cin >>n;
    int a[MAX_SIZE];
	for(int i=0;i<n;i++)
	{
		cin >>a[i];
	}
	int k;
	cin >> k;
	cout<< (solve(0,n,a,k)?"Yes\n":"No\n");
}
