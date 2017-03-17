// 老管2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	int num;
	scanf("%d", &num);
	int a[4];

	a[0] = num / 1000;
	a[1] = num / 100 % 10;
	a[2] = num / 10 % 10;
	a[3] = num / 1 % 10;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != 0)
		{
			printf("%d", (a[i] + (4 - i)) % 10);
		}
	}
    return 0;
}

