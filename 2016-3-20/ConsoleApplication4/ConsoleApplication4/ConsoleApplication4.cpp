// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class  MyClass
{
	int a;
	int *p = &a;
public:
	MyClass(int b) :a(b) { cout << a << endl; };
	//MyClass(const MyClass &c) { a = c.a; cout << a<< b << endl;}
	int get() const { return a; };
};
int main()
{
	MyClass aa(0), bb(aa);
	return 0;
}
