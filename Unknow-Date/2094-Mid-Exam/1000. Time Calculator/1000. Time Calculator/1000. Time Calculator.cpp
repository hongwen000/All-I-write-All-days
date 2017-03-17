// 1000. Time Calculator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int InputNumber(0);
	int Answer_Hour(0), Answer_Minute(0), Answer_Second(0);
	cin >> InputNumber;
	if (!(InputNumber >= 0 && InputNumber <= 86400))
	{
		exit(0);
	}
	Answer_Hour = InputNumber / 3600;
	Answer_Minute = (InputNumber - Answer_Hour * 3600) / 60;
	Answer_Second = InputNumber - Answer_Hour * 3600 - Answer_Minute * 60;
	cout << Answer_Hour<< " hour(s) " << Answer_Minute << " minute(s) " << Answer_Second << " second(s)"<< endl;
    return 0;
}

