// SOJ1021. Couples.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

int main()
{
	int couple_number(100);
	//while (couple_number)
	//{
		//cin >> couple_number;
		list <int> CC(2 * couple_number);
		list <int> ::iterator i;
		//int index(0);
		for (int n = /*0*/1; n <=/*<*/ 2 * couple_number; n++)
		{
			//cin >> index;
			i = CC.begin();
			for (int p = 0; p < /*index*/n - 1; p++)
			{
				i++;
			}
			*i = (n / 2) + 1;
		}
		static int len_before = CC.size();
		static int len_after = CC.size() - 1;
		while (!CC.empty() && len_before != len_after)
		{
			len_before = CC.size();
			len_after = CC.size();
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
							CC.erase(temp);
							CC.erase(temp2);
							i = CC.begin();
							len_after = CC.size();
						}
					}
					else
					{
						if (*temp == *CC.begin())
						{
							CC.erase(temp);
							list <int> ::iterator temp4 = CC.begin();
							CC.erase(temp4);
							if (CC.empty())
							{
								cout << "YES" << endl;
								len_after = CC.size();
								break;
							}
							else
							{
								i = CC.begin();
								len_after = CC.size();
							}
						}
					}
				}
			}
		}
		if (!CC.empty())
		{
			cout << "NO" << endl;
		}
	//}
	return 0;
}