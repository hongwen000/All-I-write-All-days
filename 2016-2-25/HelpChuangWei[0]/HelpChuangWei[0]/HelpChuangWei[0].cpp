// HelpChuangWei[0].cpp : �������̨Ӧ�ó������ڵ㡣
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

