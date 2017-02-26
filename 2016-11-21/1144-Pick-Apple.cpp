#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    
    int height[10];
    int count=0;
    for(int i=0;i<10;i++)
        cin >>height[i];
	int hand;
	cin >>hand;
	for(int i=0;i<10;i++)
		count+=(height[i]<=hand+30)?1:0;
	cout<<count<<endl;
	return 0;
}