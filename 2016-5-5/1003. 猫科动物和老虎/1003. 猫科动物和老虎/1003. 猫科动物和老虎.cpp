// 1003. 猫科动物和老虎.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Cat
{
	int data;
public:
	Cat();
	Cat(int n);
	~Cat();
};

class Tiger : public Cat
{
	int data;
public:
	Tiger(int n);
	~Tiger();
};

int main()
{
	Cat bc;
	Tiger dc(6);
	Tiger dc1(18);

	return 0;
}

Cat::Cat():data(0)
{
	cout << "Default Constructor of Cat is Running" << endl;
}

Cat::Cat(int n):data(n)
{
	cout << "Constructor of Cat is Running " << n << endl;
}

Cat::~Cat()
{
	cout << "Destructor of Cat is Running " << data << endl;
}

Tiger::Tiger(int n):data(n),Cat(n)
{
	cout << "Constructor of Tiger is Running " << n << endl;
}

Tiger::~Tiger()
{
	cout << "Destructor of Tiger is Running " << data << endl;
}
