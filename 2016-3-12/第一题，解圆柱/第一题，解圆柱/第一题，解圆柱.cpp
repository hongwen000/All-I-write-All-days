// 第一题，解圆柱.cpp : 定义控制台应用程序的入口点。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int main()
{
	float PI = 3.1415;
	float radius, hight, bottom_area,side_area,volume;
	printf("请输入圆柱的高和半径");
	scanf("%f %f", &radius, &hight);
	bottom_area = PI * pow(radius, 2);
	side_area = 2 * PI * radius;
	volume = bottom_area*hight;
	printf("圆柱的底面积是%f，侧面积是%f，高是%f", bottom_area, side_area, volume);
    return 0;
}

