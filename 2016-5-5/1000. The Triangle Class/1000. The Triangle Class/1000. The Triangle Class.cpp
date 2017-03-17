// 1000. The Triangle Class.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cmath>
class GeometricObject
{
public:
	GeometricObject()
	{
		color = "white";
		filled = false;
	}
	GeometricObject(string color, bool filled)
	{
		this->color = color;
		this->filled = filled;
	}

	string getColor()
	{
		return color;
	}

	void setColor(string color)
	{
		this->color = color;
	}

	bool isFilled()
	{
		return filled;
	}

	void setFilled(bool filled)
	{
		this->filled = filled;
	}

	string toString()
	{
		return "Geometric object color " + color +
			" filled " + ((filled) ? "true" : "false");
	}
private:
	string color;
	bool filled;
};

class Triangle : public GeometricObject
{
public:
	Triangle ();
	Triangle(double  _side1, double _side2, double _side3);
	~Triangle ();
	double getside1();
	double getside2();
	double getside3();
	double getArea();
	double getPerimeter();
private:
	double side1, side2, side3;
};

Triangle ::Triangle ():side1(1.0),side2(1.0),side3(1.0)
{

}

Triangle::Triangle(double _side1, double _side2, double _side3):side1(_side1),side2(_side2),side3(_side3)
{
	if (!(side1 + side2 > side3&&side1 + side3 > side2&&side2 + side3 > side1))
	{
		cout << "illegal sides!" << endl;
		side1 = 1.0;
		side2 = 1.0;
		side3 = 1.0;
	}
}


Triangle ::~Triangle ()
{
}

double Triangle::getside1()
{
	return side1;
}

double Triangle::getside2()
{
	return side2;
}

double Triangle::getside3()
{
	return side3;
}

double Triangle::getArea()
{
	double a = (side1 + side2 + side3) / 2.0;
	double Aera = sqrt(a*(a - side1)*(a - side2)*(a - side3));
	return Aera;
}

double Triangle::getPerimeter()
{

	return side1+side2+side3;
}

int main()
{
	Triangle tri1;
	Triangle tri2(3.0, 4.0, 5.0);
	cout << tri2.getArea() << endl;
	cout << tri2.getPerimeter() << endl;
    return 0;
}

