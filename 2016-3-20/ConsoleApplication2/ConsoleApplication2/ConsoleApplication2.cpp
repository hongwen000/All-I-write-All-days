// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdio.h>
int main()
{
	int math,eng,comp,average;
	scanf("%d%d%d", &math, &eng, &comp);
	average = (math + eng + comp) / 3;
	printf("math=%d,eng=%d,comp=%d,average=%d\n", math, eng, comp, average);
    return 0;
}

