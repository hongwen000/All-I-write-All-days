// HelpChuangWei[0].cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << "number" << n << "factor=";
	for (int k(1); k <= n; k++)
	{
		if (n%k == 0)
		{
			cout << k << " ";
		}
	}
	//cout <<endl;
    return 0;
}

