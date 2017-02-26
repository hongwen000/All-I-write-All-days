// 1150-Magic-board.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;
#include <string>
#include <cmath>
int dst[2][4];
string str = "ABC";
bool found = false;
bool equ(int now[][4])
{
	bool flag = true;
	for (int i = 0; i<8; i++)
		flag = flag && (now[i / 4][i % 4] == dst[i / 4][i % 4]);
	return flag;
}
void m1(int now[][4])
{
	for (int i = 0; i<4; i++)
	{
		int temp = now[0][i];
		now[0][i] = now[1][i];
		now[1][i] = temp;
	}
}
void m2(int now[][4])
{
	int _now[2][4];
	for (int i = 0; i<8; i++)
		_now[i / 4][i % 4] = now[i / 4][i % 4];
	for (int j = 0; j<2; j++)
	{
		for (int i = 0; i<4; i++)
		{
			now[j][i] = _now[j][(i + 4 - 1) % 4];
		}
	}

}
void m3(int now[][4])
{
	int _now[2][4];
	for (int i = 0; i<8; i++)
		_now[i / 4][i % 4] = now[i / 4][i % 4];
	now[0][1] = _now[1][1];
	now[0][2] = _now[0][1];
	now[1][1] = _now[1][2];
	now[1][2] = _now[0][2];
}
int bfs(int _now[][4], int depth, int method, string proc)
{
	int now[2][4];
	for (int i = 0; i<8; i++)
		now[i / 4][i % 4] = _now[i / 4][i % 4];
	if (depth <= 0)
		return 0;
	else
	{
		if (method == 1)
			m1(now);
		else if (method == 2)
			m2(now);
		else
			m3(now);
		if (equ(now))
		{
			proc = proc+ str[method - 1];
			if (!found)
			{
				cout << proc << endl;
				found = true;
			}
			return 1;
		}
		else
		{
			bool result = true;
			for (int i = 1; i <= 3; i++)
			{
				bool _result = bfs(now, depth-1, i, proc + str[method - 1]);
				result = result || _result;
			}
			return result;
		}
	}
}
int main()
{
	int T;
	while (cin >> T && T != -1)
	{
		string proc;
		for (int i = 0; i<8; i++)
			cin >> dst[i / 4][i % 4];
		int ori[2][4] = { 1,2,3,4,8,7,6,5 };
		bool result = true;
		found = false;
		for (int i = 1; i <= 3; i++)
		{
			bool _result = bfs(ori, T, i, proc);
			result = result || _result;
		}
		if (!result)
			cout << "-1" << endl;

	}
}
