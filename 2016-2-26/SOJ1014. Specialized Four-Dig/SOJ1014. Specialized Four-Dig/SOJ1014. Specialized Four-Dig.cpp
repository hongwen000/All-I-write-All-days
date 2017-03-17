// SOJ1014. Specialized Four-Dig.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int sum(string a)
{
	int sum = 0;
	for (int i = 0; i < a.length(); i++)
	{
		switch (a.at(i))
		{
		case '1':sum += 1;
			break;
		case '2':sum += 2;
			break;
		case '3':sum += 3;
			break;
		case '4':sum += 4;
			break;
		case '5':sum += 5;
			break;
		case '6':sum += 6;
			break;
		case '7':sum += 7;
			break;
		case '8':sum += 8;
			break;
		case '9':sum += 9;
			break;
		case '0':sum += 0;
			break;
		case'a':sum += 10;
			break;
		case'b':sum += 11;
			break;
		case'c':sum += 12;
			break;
		case'd':sum += 13;
			break;
		case'e':sum += 14;
			break;
		case'f':sum += 15;
			break;
		default:
			break;
		}
	}
	return sum;
}
int sum(int n)
{
	int sum=0;
	while (n != 0)
	{
		sum+= n%10;
		n /= 10;
	}
	return sum;
}
int main()
{
for (int i = 2992; i <= 9999; i++)
{

		char  a[5],  b[5];
		_itoa_s(i, a, 16);
		_itoa_s(i, b, 12);
		string sa(a), sb(b);
		if(sum(sa)==sum(sb)&& sum(sb) ==sum(i) &&sum(sa) == sum(i))
		cout << i<<endl;

}
    return 0;
}

