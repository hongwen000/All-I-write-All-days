// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int main()
{
	float PI = 3.1415;
	float radius, hight, bottom_area, side_area, volume;
	printf("请输入圆柱的半径和高\n");
	scanf("%f %f", &radius, &hight);
	bottom_area = PI * pow(radius, 2);
	side_area = 2 * PI * radius;
	volume = bottom_area*hight;
	printf("圆柱的底面积是%.2f，侧面积是%.2f，高是%.2f", bottom_area, side_area, volume);
	return 0;
}
