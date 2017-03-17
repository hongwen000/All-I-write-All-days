// helpAnLaojie.cpp : 定义控制台应用程序的入口点。
//

#pragma warning(disable : 4996)
#include "stdafx.h"
#include <stdio.h>

int main()
{
	int x, y;
	scanf("%d", &x);
	if (x < 20)
	{
		y = 1;
	}
	else if (x < 30)
	{
		y = 2;
	}
	else if (y < 40)
	{
		y = 3;
	}
	else if (x < 50)
	{
		y = 4;
	}
	else if (x < 60)
	{
		y = 5;
	}
	else
	{
		y = 6;
	}
	printf("x=%d,y=%d\n", x, y);
    return 0;
}

