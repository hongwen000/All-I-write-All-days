// 老管1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int is(int m) {
	int i;  
	int k;  
	k = (int)sqrt((double)m);
	for (i = 2; i <= k; i++)
		if (m%i == 0)
			break;
	if (i>k)
		return 1;
	else
		return 0;
	
}
void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	const int MAX = 10;
	int number[10][2];
	for (int n = 0; n < 10;n++)
	{
		scanf("%d", &number[n][0]);
		number[n][1] = is(number[n][0]);
	}
	int i = 0, j = 9;
	for (i; i < MAX; i++ )
	{
		if (number[i][1] == 1)
		{
			for (j; j > i; j--)
			{
				if (number[j][1] == 1)
				{
					swap(&number[i][0], &number[j][0]);
					j--;
					break;
				}
			}
		}
		printf("%d ", number[i][0]);
	}
    return 0;
}

