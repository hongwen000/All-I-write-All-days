// Upercase2Lower.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned char a;
	cin >> a;
	a = a | 0b00100000;
	cout << a << endl;
    return 0;
}

