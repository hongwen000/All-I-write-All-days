// 绩点计算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{ 
	double GPA, grade;
	cin >> grade;
	if (grade < 0 | grade >100)
		cout << "Invalid" << endl;
	else if (grade < 60)
		cout << "Failed" << endl;
	else
		cout <<fixed<<setprecision(1)<< (grade - 50) / 10 << endl;
    return 0;
}

