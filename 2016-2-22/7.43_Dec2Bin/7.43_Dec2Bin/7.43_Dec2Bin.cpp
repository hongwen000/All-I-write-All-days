// 7.43_Dec2Bin.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;
void dec2Bin(int value, char binaryString[])
{
	itoa(value, binaryString, 2);
}
int main()
{

    return 0;
}

