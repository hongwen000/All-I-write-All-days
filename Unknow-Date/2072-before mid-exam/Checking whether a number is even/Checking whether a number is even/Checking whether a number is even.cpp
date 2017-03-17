// Checking whether a number is even.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (a = a % 2 ? 1 : 0)
	{
		cout << "false" << endl;
	}
	else
	{
		cout << "true" << endl;
	}
	return 0;
}
