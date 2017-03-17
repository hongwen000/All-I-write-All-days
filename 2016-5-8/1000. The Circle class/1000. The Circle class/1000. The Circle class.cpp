// 1000. The Circle class.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class Circle
{
public:
	Circle();
	Circle(double);
	double getArea();
	double getRadius();
	void setRadius(double);
	// add any member needed here
	bool operator<(Circle &secondCircle);
	bool operator<=(Circle &secondCircle);
	bool operator>(Circle &secondCircle);
	bool operator>=(Circle &secondCircle);
	bool operator!=(Circle &secondCircle);
	bool operator==(Circle &secondCircle);
private:
	double radius;
};

// Construct a circle object
Circle::Circle()
{
	radius = 1;
}

// Construct a circle object
Circle::Circle(double newRadius)
{
	radius = newRadius;
}

// Return the area of this circle
double Circle::getArea()
{
	return radius * radius * 3.14159;
}

// Return the radius of this circle
double Circle::getRadius()
{
	return radius;
}

// Set a new radius
void Circle::setRadius(double newRadius)
{
	radius = (newRadius >= 0) ? newRadius : 0;
}

bool Circle::operator<(Circle & secondCircle)
{
	return this->getRadius() < secondCircle.getRadius() ? true : false;
}

bool Circle::operator<=(Circle & secondCircle)
{
	return this->getRadius() <= secondCircle.getRadius() ? true : false;
}

bool Circle::operator>(Circle & secondCircle)
{
	return this->getRadius() > secondCircle.getRadius() ? true : false;
}

bool Circle::operator>=(Circle & secondCircle)
{
	return this->getRadius() >= secondCircle.getRadius() ? true : false;
}

bool Circle::operator!=(Circle & secondCircle)
{
	return this->getRadius() != secondCircle.getRadius() ? true : false;
}

bool Circle::operator==(Circle & secondCircle)
{
	return this->getRadius() == secondCircle.getRadius() ? true : false;
}



int main()
{
    return 0;
}

