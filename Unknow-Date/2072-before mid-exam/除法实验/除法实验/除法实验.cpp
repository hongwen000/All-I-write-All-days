// 除法实验.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int i;
	int k;
	int j;
	char a = 'a';
	char b;
	i = 3;
	k = (-2);
	cout << "3/-2=" << i / k << endl;
	i = -3;
	k = -2;
	cout << "-3/2=" << i / k << endl;
	b = a && 1;
	cout << "a&&1=" << b << endl;
	b = a && true;//进行了隐式类型转换
	cout << "先将a赋值为a&&ture再输出，结果是" << b << endl;
	b = a && 2;
	cout << "a&&2=" << b << endl;
	b = a & true;
	cout << "a&ture=" << b << endl;
	b = a && 1;
	cout << "(int)a&&1=" << (int)b << endl;
	b = a && true;
	cout << "先将a赋值为(int)a&&ture再输出，结果是" << (int)b << endl;
	b = a && 2;
	cout << "(int)a&&2=" << (int)b << endl;
	b = a & true;
	cout << "(int)a&ture=" << (int)b << endl;
	cout << "若无括号直接输出a&&ture=" << a && true;
	cout << endl;
	cout << "用Cout语句输出(a&&ture)，结果是" << (a && true)<<endl;
	int d(3), e(4), f(5);
	i = 1; k = 2;
	j = i, k, d, e, f;
	cout << "i = 1; k = 2;d = 3;e = 4;f = 5;j = i, k, d, e, f;最后j= " << j << endl;
	j = (i, k, d, e, f);
	cout << "i = 1; k = 2;d = 3;e = 4;f = 5;j = (i, k, d, e, f);最后j= " << j << endl;
	i = 0;
	cout <<( (i++, i) ? 1: 0 )<< endl;
	bool bl;
	switch (bl)
	{
	case 0: {
		cout << "case 0 OK" << endl;
		break;
	}
	case 1: {
		cout << "case 1 OK" << endl;
		break;
	}
	default:
		break;
	}
	system("pause");
	return 0;
}

