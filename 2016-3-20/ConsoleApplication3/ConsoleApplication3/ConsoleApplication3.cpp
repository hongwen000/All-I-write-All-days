// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class base {
public:
	int base_;
	base(){}
	base(int base_) { cout << base_; }
};
class a:base 
{
public:
	int & b()const;
	int c = 0;
	void show(int aa) { cout << c; }
	a(int v) :base(v) { cout << v; };
private:
	int d = 0;
	int base = 0;
};


int main()
{
	a f(1);
	int d = f.b();
    return 0;
}

int  a::b() const
{
	static int c;
	return &c;
	// TODO: �ڴ˴����� return ���
}
