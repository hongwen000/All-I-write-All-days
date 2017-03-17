// 1000. Rabbit.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<cstring>
using namespace std;
int num[150][150];
int main()
{
	int m, d;
	while (cin >> m >> d, m != 0 || d != 0)
	{
		memset(num, 0, sizeof(num));
		num[1][1] = 1;
		for (int i = 2; i <= d + 1; i++)
		{
			if (i <= m)
			{
				num[i][1] = num[i - 1][1] + 1;
				if (num[i][1] >= 10)
				{
					int v = num[i][1] / 10;
					num[i][1] = num[i][1] % 10;
					num[i][2] += v;
				}
			}
			else
			{
				int w = 0;
				for (int n = 1; n < 150; n++)
				{
					num[i][n] = num[i - 1][n] + num[i - m][n] + w;
					w = 0;
					if (num[i][n] >= 10)
					{
						w = num[i][n] / 10;
						num[i][n] = num[i][n] % 10;
					}
				}
			}
		}
		for (int i = 149; i >= 1; i--)
		{
			if (num[d + 1][i] != 0)
			{
				for (int j = i; j >= 1; j--)
					cout << num[d + 1][j];
				cout << endl;
				break;
			}
		}
	}
	return 0;
}

