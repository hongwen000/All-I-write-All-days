#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >>T;
	while((T--))
	{
		int arr[1000];
		int N;
		cin >>N;
		for(int i=0;i<N;i++)
		{
			cin >>arr[i];
		}
		sort(arr,arr+N);
		for(int i=0;i<N;i++)
		{
			cout <<arr[i]<<endl;
		}
	}
}

