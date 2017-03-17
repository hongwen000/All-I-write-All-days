// 1000. Extending MyPoint class.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
class MyPoint
{
private:
	double x, y;
public:
	// The no-arg constructor that contruccts a point with coordinates(0,0)
	MyPoint();

	MyPoint(double x, double y);
	double getX() const;
	double getY() const;

	//display the distance between two points in two-dimensional space.
	double distance(const MyPoint &point);
};

class ThreeDPoint:MyPoint
{
private:
	double z;
public:
	// The no-arg constructor that contruccts a point with coordinates(0,0,0)  
	ThreeDPoint();

	ThreeDPoint(double x, double y, double z);
	double getZ() const;

	//display the distance between two points in Three-dimensional space.
	double distance(const ThreeDPoint &point);
};

int main()
{
	MyPoint _2D(1,1);
	ThreeDPoint _3D(1, 1, 1);
	cout << _3D.distance(_3D) <<endl;
    return 0;
}

MyPoint::MyPoint()
{
	x = y = 0;
}
MyPoint::MyPoint(double x, double y)
{
	this->x = x;
	this->y = y;
}

double MyPoint::getX() const
{
	return x;
}

double MyPoint::getY() const
{
	return y;
}
double MyPoint::distance(const MyPoint &point)
{
	return sqrt((pow(point.getX(), 2)+ pow(point.getY(), 2)));
}

ThreeDPoint::ThreeDPoint():MyPoint::MyPoint(),z(0)
{

}

ThreeDPoint::ThreeDPoint(double x, double y, double z) : MyPoint(x,y),z(z)
{
}

double ThreeDPoint::getZ() const
{
	return z;
}

double ThreeDPoint::distance(const ThreeDPoint & point)
{
	return sqrt(pow(point.getX(),2)+ pow(point.getY(), 2)+ pow(point.getZ(), 2));
}
