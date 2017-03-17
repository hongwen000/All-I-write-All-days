// Transfer Two Dimention Array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
void IO(int ** arr,int a,int b)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> arr[i][j];
			cout << arr[i][j];

		}
	}
}

int main()
{
	static int ** arr;
	int a(0), b(0);
	cin >> a>>b;
	arr =(int**) new int *[a];
	for (int n = 0; n < b; n++)
	{
		arr[n] = (int *)new int[b];
	}
	IO(arr, a, b);
	return 0;
}

