// Check Point 7.19.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cstring>

int main()
{
	char s1[] = "abc";
	char s2[] = "efg";
	if (s1 < s2)
	{
		cout << "b T \"abc\" < \"efg\" " << endl;
	}
	else
	{
		cout << "b F \"abc\" >= \"efg\" " << endl;
	}
	cout << "c T s1[0] is " << s1[0] << endl;
	if (s1[0] < s2[0])
	{
		cout << "d T" << endl;
	}
	else
	{
		cout << "d F" << endl;
	}
	errno_t s3 = strcpy_s(s1, s2);
	cout << "e T" << " s1 is " << s1 << " and strcpy_s() returns " << s3 << endl;
	strcpy_s(s1, "abc");
	cout << "f T answer is " << strcmp(s1, s2) << endl;
	cout << "g T answer is " << strlen(s1) << endl;
	if ("ac" < "ab")
	{
		cout << " \"ac\" < \"ab\" " << endl;
	}
	else if ("ac" == "ab")
	{
		cout << " \"ac\" = \"ab\" " << endl;
	}
	else
	{
		cout << " \"ac\" > \"ab\" " << endl;
	}
    return 0;
}

