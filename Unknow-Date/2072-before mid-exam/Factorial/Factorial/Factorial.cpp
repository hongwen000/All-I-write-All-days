// Factorial.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int answer(1);
int Factorial(int value)
{
	if (value == 0)
		return answer;
	answer *= value;
	value--;
	Factorial(value);
}
int main()
{
	int value;
	cin >> value;
	cout << Factorial(value) << endl;
    return 0;
}

