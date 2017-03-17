// 1003. Square.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void draw(int Side_Length = 0)
{
	for (int y = 0; y < Side_Length; y++)
	{
		for (int x = 0; x < Side_Length; x++)
		{
			if (x + y == Side_Length-1 || x == y)
				cout << 'X';
			else
				cout << '.';
		}
		cout << endl;
	}
}
int main()
{
	int Cases(0);
	cin >> Cases;
	for (int i = 0; i < Cases; i++)
	{
		int Side_Length(0);
		cin >> Side_Length;
		draw(Side_Length);
	}
    return 0;
}

