// Odd or Even.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int n(0),t(0),a(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		t = t + (a % 2 ? 1 : 0);
	}
	cout << t << endl;
    return 0;
}

