// 1027. MJ, Nowhere to Hide.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
void inc(string * (&p));
void inc(int * (&p));
int main()
{
	int n;
	while (cin >> n,n!=0)
	{
		string * p_name = new string [n];
		string * p_ip = new string [n];
		string * p_name_head = p_name;
		string * p_ip_head = p_ip;
		for (int i = 0; i < n; i++)
		{
			cin >> *p_name;
			cin >> *p_ip;
			inc(p_name);
			inc(p_ip);
		}
		int * position=new int [n];
		int * position_head = position;
		string * p_name_iter1 = p_name_head;
		string * p_ip_iter1 = p_ip_head;
		string * p_name_iter2 = p_name_head;
		string * p_ip_iter2 = p_ip_head;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				inc(p_ip_iter2);
				if (*p_ip_iter1 == *p_ip_iter1)
				{
					*position = i;
				}
				inc(p_ip_iter1);
			}
			int *position_iter = position_head;
			for (int i = 0; i < n-1; i++)
			{
				cout << *position_iter << endl;
				inc(position);
			}
			cout << *position_iter << endl;

		}
	}
    return 0;
}

void inc(string *(&p))
{
	p += sizeof(*p);
}

void inc(int *(&p))
{
	p += sizeof(int);
}
