// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
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

