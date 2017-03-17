// calculating the future investment value.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double accumulatedValue, investmentAmount, annualPercentage,mounthlyInterestRate, numberOfYears;
	cin >> investmentAmount >> annualPercentage >> numberOfYears;
	mounthlyInterestRate = annualPercentage / 1200;
	accumulatedValue = investmentAmount * pow((1 + mounthlyInterestRate),(numberOfYears * 12));
	cout << fixed <<setprecision(2)<< accumulatedValue << endl;
	return 0;
}

