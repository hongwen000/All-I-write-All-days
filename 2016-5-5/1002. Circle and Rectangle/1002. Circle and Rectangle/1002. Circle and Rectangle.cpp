// 1002. Circle and Rectangle.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
const double PI = 3.14;
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
	double x, y;
public:

	Point();
	Point(double x, double y);
	Point(Point& pt);
	double getx();
	double gety();
};
class Rectangle : public Point
{
public:
	Rectangle();
	Rectangle(double x, double y, double width, double length);
	double Getlength();
	double Getwidth();
	double Getarea();
	int position(Point &pt);
	~Rectangle();

private:
	double width, length;
};



Rectangle::Rectangle():Point(0,0),length(0),width(0)
{
}

Rectangle::Rectangle(double x, double y, double width, double length) : Point(x, y), length(length), width(width)
{
}

double Rectangle::Getlength()
{
	return length;
}

double Rectangle::Getwidth()
{
	return width;
}

double Rectangle::Getarea()
{
	return width*length;
}

int Rectangle::position(Point & pt)
{
	double s1, s2;
	s1 = (pt.getx() - getx()); 
	s2 = (pt.gety() - gety());
	if (((s1 == 0 || s1 == width) && s2 <= length) || ((s2 == 0 || s2 == length) && s1 <= width))
		return 0;
	else if (s1 < width&&s2 < length)
		return -1;
	else 
		return 1; 
}

Rectangle::~Rectangle()
{
}

class Circle:Point
{
public:
	Circle();
	Circle(double x, double y, double radius);
	~Circle();
	double getradius();
	int position(Point &pt);
private:
	double radius;
};

Circle::Circle() :Point(0,0),radius(0)
{
}

Circle::Circle(double x, double y, double radius) : Point(x, y) , radius(radius)
{

}

Circle::~Circle()
{
}

double Circle::getradius()
{
	return radius;
}


int Circle::position(Point & pt)
{
	double distance = sqrt((getx() - pt.getx())*(getx() - pt.getx()) + (gety() - pt.gety())*(gety() - pt.gety()));
	double s = distance - radius;
	if (s == 0) return 0;
	else if (s<0) return -1; 
	else return 1; 

}

Point::Point(double x, double y) :x(x), y(y)
{
}

Point::Point(Point & pt)
{
	this->x = pt.getx();
	this->y = pt.gety();
}

Point::Point() 
{
	x = 0;
	y = 0;
}
double Point::getx()
{
	return x;
}

double Point::gety()
{
	return y;
}


int main()
{
	Circle cc1(3, 4, 5);
	Rectangle rt1(0, 0, 6, 8);
	Point p1(0, 0);
	cout << "point p1:";
	switch (rt1.position(p1))
	{
	case 0:cout << "on-rectangle" << endl; break;
	case -1:cout << "inside-rectangle" << endl; break;
	case 1:cout << "outside-rectangle" << endl; break;
	}
	switch (cc1.position(p1))
	{
	case 0:cout << "on-circle" << endl; break;
	case -1:cout << "inside-circle" << endl; break;
	case 1:cout << "outside-circle" << endl; break;
	}
	return 0;
}