// numeric computation_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include  <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int a, b, c;
	double x, y;
	cin >> a >> b >> c >> x >> y;
	cout << fixed << setprecision(3) << 1200.0 / (24 - 4.0 * 5.0) << endl << c * (pow(pow(a, 2) + pow(b, 2), (1.0 / 2.0))) << endl << log(log(pow(10.0, 3.5) + 2)) << endl << y + a % 5 * (int)(x + y) / 2 % 4 << endl;
    return 0;
}

