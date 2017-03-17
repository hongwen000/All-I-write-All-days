// The area of triangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;
double get_l(double a, double b, double c, double d)
{
	double l;
	l = sqrt(pow((a - c), 2)+ pow((b - d), 2));
	return l;
}
int main()
{
	double x[3], y[3], l[3],square,q;
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}
	l[0] = get_l(x[0], y[0], x[1], y[1]);
	l[1] = get_l(x[0], y[0], x[2], y[2]);
	l[2] = get_l(x[1], y[1], x[2], y[2]);
	if (l[0] + l[1] < l[2] | l[0] + l[2] < l[1] | l[1] + l[2] < l[0]) {
		exit(0);
	}
	q = (l[0] + l[1] + l[2])/2;
	square = sqrt(q*(q - l[0])*(q - l[1])*(q - l[2]));
	cout << fixed<< setprecision(2) <<square << endl;
    return 0;
}

