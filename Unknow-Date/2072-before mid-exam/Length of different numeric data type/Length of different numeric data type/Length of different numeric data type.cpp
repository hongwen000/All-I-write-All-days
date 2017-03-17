// Length of different numeric data type.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << sizeof(short int)<<' '<<sizeof(unsigned short int)<<' '<< sizeof(int)<<' '<< sizeof(unsigned int)<<' '<< sizeof(long float)<<' '<< sizeof(unsigned long float)<<' '<< sizeof(float)<<' '<< sizeof(double)<<' '<< sizeof (long double)<<endl;
    return 0;
}

