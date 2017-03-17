// calculating interest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double annualInterestRate, balance,interest;
	cin >> balance >> annualInterestRate;
	interest = balance * (annualInterestRate / 1200);
		cout << fixed << setprecision(5) << interest << endl;
	return 0;
}
