#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#include "source.h"

struct Point{
	int x,y;
	bool operator<(const Point& p) {
		return (x<p.x || (x==p.x&&y<p.y));
	}
};

int main()
{
	//freopen("test01.in", "r", stdin);
	//freopen("test01.out", "w", stdout);


	{
	int A[5] = { 2, 10, 8, 6, 9 };
	cout<<find_lower_bound(A, 5, 9)<<endl;
	}
	{
	int A[5] = { 2, 10, 8, 2, 9 };
	cout<<find_lower_bound(A, 5, 3)<<endl;
	}
	{
	int A[5] = { 2, 1, 2, 6, 9 };
	cout<<find_lower_bound(A, 5, 1)<<endl;
	}

	double B[5] = { 3.0, 4.5, 6.0, 5.1, 1.3 };
	cout<<find_lower_bound(B, 5, 5.2)<<endl;

	Point C[5] = { {1,2},{2,3},{4,5},{1,3},{2,4}};
	Point c={3,2};
	cout<<find_lower_bound(C,5,c)<<endl;

	return 0;
}
