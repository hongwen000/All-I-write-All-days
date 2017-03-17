// SOJ1001. Alphacode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
static int summ(0);
int deal2(string a)
{
	int sum(0);
	int temp;
	temp = stoi(a);
	if (temp<=26)
	{
		sum += 1;
	}
	if (temp %10!=0)
	{
		sum += 1;
	}
	if (temp / 10 != 0)
	{
		sum += 1;
	}
	return sum;
}
int deal2(string a, int n)
{
	int sum(0);
	int temp;
	int stoia= stoi(a);
	for (int i = 0; (i < (a.length() - n) / 2); i++)
	{
		stoia =  stoia/ 100;
	}
	temp = stoia - (stoia / 100) * 100;
	if (temp <= 26)
	{
		sum += 1;
	}
	if (temp % 10 != 0)
	{
		sum += 1;
	}
	if (temp / 10 != 0)
	{
		sum += 1;
	}
	return sum;
}

int deal1(string a)
{
	return 1;
}
void calc(string a,int n)
{
	if (n == 2)
	{
		summ+=deal2(a);
	}
	else if (n == 1)
	{
		summ +=deal1(a);
	}
	else if (n == 0)
	{
	}
	else
	{
		summ+=deal2( a,  n);
		calc( a, n - 2);
	}

}
int main()
{
	string a("a");
	while (a != "0")
	{
		cin >> a;
		calc(a, a.length());
		cout <<summ<<endl;
	}
    return 0;
}

