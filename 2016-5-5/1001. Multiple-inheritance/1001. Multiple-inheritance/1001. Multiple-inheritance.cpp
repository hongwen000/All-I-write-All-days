// 1001. Multiple-inheritance.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A
{
public:
	A(int a0) :a(a0) {}
	void showA() { cout << a << endl; }
protected:
	int a;
};

class C
{
public:
	C(int c0) :c(c0) {}
	void showC() { cout << c << endl; }
protected:
	int c;
};

class B : public A, public C
{
public:
	B(int a,int c);
private:

};




int main()
{
	B b(11,22);
	b.showA();
	b.showC();
    return 0;
}



B::B(int a=11, int c=22) : A(a),C(c)
{
}
