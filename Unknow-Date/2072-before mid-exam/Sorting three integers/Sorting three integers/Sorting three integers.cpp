// Sorting three integers.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x)
{
	if (x < -1)
	{
		return x + 1;
	}
	else if (x < 1 && x >= -1)
	{
		x = abs(x);
		return x;
	}
	else
	{
		x = log10(x);
		return x;
	}
}
int main()
{
	double x,y;
	cin >> x;
	y = f(x);
	cout << fixed << setprecision(2) << y << endl;
    return 0;
}

