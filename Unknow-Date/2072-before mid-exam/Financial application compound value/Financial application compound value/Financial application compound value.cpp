// Financial application compound value.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double annual_interest, month_interest, o_value,a_value;
	cin >> o_value >> annual_interest;
	int i;
	month_interest = annual_interest / 1200;
	const double rate = (1 + month_interest);
	a_value = o_value*rate;
	for (i = 5; i > 0; --i)
	{
		a_value = (o_value + a_value)*rate;
	}
	cout << fixed << setprecision(2) << a_value << endl;
	return 0;
}

