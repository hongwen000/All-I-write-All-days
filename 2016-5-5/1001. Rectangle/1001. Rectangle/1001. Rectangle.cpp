// 1001. Rectangle.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
	int x, y;
public:
	Point(int x, int y);
	void Move(int x, int y);
	int Getx();
	int Gety();
};
class Rectangle : public Point
{
public:
	Rectangle(int x,int y,int length,int width);
	int Getlength();
	int Getwidth();
	int Getarea();
	~Rectangle();

private:
	int width, length;
};



Rectangle::Rectangle(int x, int y, int length,int width) : Point(x,y), length(length),width(width)
{
}

int Rectangle::Getlength()
{
	return length;
}

int Rectangle::Getwidth()
{
	return width;
}

int Rectangle::Getarea()
{
	return width*length;
}

Rectangle::~Rectangle()
{
}

int main()
{
	int x, y, length, width, xmove, ymove;
	cin >> x >> y;
	cin >> length >> width;
	Rectangle R(x, y, length, width);
	cin >> xmove >> ymove;
	R.Move(xmove, ymove);
	cout << R.Getx() << " " << R.Gety() << " "<< R.Getlength() << " " << R.Getwidth()<< " " << R.Getarea() << endl;
    return 0;
}

Point::Point(int x, int y):x(x),y(y)
{
}

void Point::Move(int x, int y)
{
	this->x += x;
	this->y += y;
}

int Point::Getx()
{
	return x;
}

int Point::Gety()
{
	return y;
}
