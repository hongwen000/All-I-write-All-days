// 1004. Constructor and inheritance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A
{
public:
	A(int a0) :a(a0) {}
	void show() { cout << "a=" << a << endl; }
private:
	int a;
};
class B:public A
{
public:
	B(int, int);
	void show();
private:
	int b;
};
int main()
{
	B b(1, 2);
	b.show();
	return 0;
}

B::B(int a0, int b0) :A(a0),b(b0)
{

}

void B::show()
{
	A::show();
	cout << "b=" << b << endl;
}
