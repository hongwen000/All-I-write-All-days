// SOJ1021.Couple.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "tchar.h"
#include <iostream>
#include <list>
using namespace std;
 
int main()
{
	int couple_number;
	wcout << "请输入秀恩爱情侣有几对d(`･_･)b" << endl;
	cin >> couple_number;
	list <int> CC(2 * couple_number);
	list <int> ::iterator i;
	int index(0);
	cout << "请输入每一对的位置σ`_`)σ" << endl;
	for (int n=0; n < 2 * couple_number; n++)
	{
		cin >> index;
		i = CC.begin();
		for (int p = 0; p < index-1; p++)
		{
			i++;
		}
		*i = (n / 2) + 1;
	}
	for (i = CC.begin(); i != CC.end(); i++)
	{
		list <int> ::iterator temp = i;
		list <int> ::iterator temp2 = i;
		list <int> ::iterator temp3 = i;
		temp3++;
		if (!CC.empty())
		{
			if (temp3 != CC.end())
			{
				if (*temp == *(++temp2))
				{
					wcout << "(#`Д´)ﾉ抓住第" <<*temp<<"对"<< endl;
					CC.erase(temp);
					CC.erase(temp2);
					wcout << "烧死，用文火" << endl;
					i = CC.begin();
				}
			}
			else
			{
				if (*temp == *CC.begin())
				{
					wcout << "(#`Д´)ﾉ抓住第" << *temp << "对" << endl;
					CC.erase(temp);
					list <int> ::iterator temp4 = CC.begin();
					CC.erase(temp4);
					wcout << "烧死，用文火" << endl;
					if (CC.empty())
					{
						cout << "恭喜大王，烧死所有秀恩爱的啦" << endl;
						break;
					}
					else
					{
						i = CC.begin();
					}
				}
			}
		}
	}
	if (!CC.empty())
	{
		cout << "艹艹艹，有几个跑了";
	}
    return 0;
}
