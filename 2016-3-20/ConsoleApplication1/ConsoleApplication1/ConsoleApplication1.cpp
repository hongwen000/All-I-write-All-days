// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int main()
{
	float PI = 3.1415;
	float radius, hight, bottom_area, side_area, volume;
	printf("������Բ���İ뾶�͸�\n");
	scanf("%f %f", &radius, &hight);
	bottom_area = PI * pow(radius, 2);
	side_area = 2 * PI * radius;
	volume = bottom_area*hight;
	printf("Բ���ĵ������%.2f���������%.2f������%.2f", bottom_area, side_area, volume);
	return 0;
}
