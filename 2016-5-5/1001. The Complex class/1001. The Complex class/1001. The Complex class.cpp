// 1001. The Complex class.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Complex
{
	double re; //real part of a complex number
	double im; //imaginary part of a complex number
public:
	double real() const { return re; }
	double imag() const { return im; }
	// add any other function needed here
	friend ostream& operator<<(ostream& out, const Complex& s);
	Complex()
	{
		re = 0;
		im = 0;
	}
	Complex(double _re)
	{
		re = _re;
		im = 0;
	}
	Complex(double _re, double _im)
	{
		re = _re;
		im = _im;
	}
	Complex(const Complex & s)
	{
		re = s.re;
		im = s.im;
	}
	Complex& operator +=(const Complex &s)
	{
		re += s.re;
		im += s.im;
		return *this;
	}
	Complex& operator -=(const Complex &s)
	{
		re -= s.re;
		im -= s.im;
		return *this;
	}
	Complex& operator *=(const Complex &s)
	{
		Complex temp(*this);
		re = temp.re * s.re - temp.im * s.im;
		im = temp.im * s.re + temp.re * s.im;
		return *this;
	}
	Complex& operator /=(const Complex &s)
	{
		Complex temp(*this);
		re = (temp.re*s.re + temp.im*s.im) / (pow(s.re, 2) + pow(s.im, 2));
		im = (temp.im*s.re - temp.re*s.im) / (pow(s.re, 2) + pow(s.im, 2));
		return *this;
	}
	friend Complex operator + (const Complex & s1, const Complex &s2);
	friend Complex operator - (const Complex & s1, const Complex &s2);
	friend Complex operator * (const Complex & s1, const Complex &s2);
	friend Complex operator / (const Complex & s1, const Complex &s2);
	Complex operator - ()
	{
		Complex temp;
		temp.re = -(this->re);
		temp.im = -(this->im);
		return temp;
	}
	friend int operator == (const Complex & s1, const Complex &s2);
	friend int operator != (const Complex & s1, const Complex &s2);
	friend istream& operator >> (istream &in, Complex &s);
};
ostream& operator<<(ostream& out, const Complex& s)
{
	out << "(" << s.re << "," << s.im<<")";
	return out;
}
Complex operator+(const Complex & s1, const Complex & s2)
{
	Complex temp;
	temp.re = s1.re + s2.re;
	temp.im = s1.im + s2.im;
	return temp;
}
Complex operator-(const Complex & s1, const Complex & s2)
{
		Complex temp;
		temp.re = s1.re - s2.re;
		temp.im = s1.im - s2.im;
		return temp;
}
Complex operator*(const Complex & s1, const Complex & s2)
{
	Complex temp;

	temp.re = s1.re * s2.re - s1.im * s2.im;
	temp.im = s1.im * s2.re + s1.re * s2.im;
	return temp;
}
Complex operator/(const Complex & s1, const Complex & s2)
{
	Complex temp;
	temp.re = (s1.re*s2.re + s1.im*s2.im) / (pow(s2.re, 2) + pow(s2.im, 2));
	temp.im = (s1.im*s2.re - s1.re*s2.im) / (pow(s2.re, 2) + pow(s2.im, 2));
	return temp;
}
int operator==(const Complex & s1, const Complex & s2)
{
	if (s1.re == s2.re && s1.im == s2.im)
		return 1;
	else
		return 0;
}
int operator!=(const Complex & s1, const Complex & s2)
{
	if (s1.re != s2.re || s1.im != s2.im)
		return 1;
	else
		return 0;
}
istream & operator>>(istream & in, Complex &s)
{
	char a;
	in >> a >> s.re >> a >> s.im >> a;
	//string temp;
	//in >> temp;
	//if (temp.empty())
	//{
	//	return in;
	//}
	//s = s - s;
	//for (int iter = temp.length() - 2,power=0,flag=0, flagDot = 0; iter > 0; iter--,power ++)
	//{
	//	if (temp.at(iter)== ',')
	//	{
	//		flag = 1;
	//		power = 0;
	//		flagDot = 0;
	//		continue;
	//	}
	//	if (temp.at(iter) == '.')
	//	{
	//		flagDot = 1;
	//		continue;
	//	}
	//	if (!flag && !flagDot)
	//	{
	//		s.im += (temp.at(iter)-48)*pow(10, power);
	//	}
	//	else if (flag && !flagDot)
	//	{
	//		s.re += ((temp.at(iter)-48)*pow(10, power))/10;
	//	}
	//	else if(!flag && flagDot)
	//	{
	//		s.im /= pow(10, power-1);
	//		power = 0;
	//		s.im += (temp.at(iter) - 48)*pow(10, power);
	//		flagDot = 0;
	//	}
	//	else
	//	{
	//		s.re /= pow(10, power - 2);
	//		power = 1;
	//		s.re += ((temp.at(iter) - 48)*pow(10, power)) / 10;
	//		flagDot = 0;
	//	}
	//}
	// TODO: 在此处插入 return 语句
	return in;
}
void f()
{
	Complex a;
	cout << a << endl; //output (0,0) 

	Complex b = Complex(1, 2.5);
	cout << b << endl; //output(1,2.5)

	Complex c(3.0);
	cout << c << endl; //output (3,0)

	c += a;
	cout << c << endl;

	c = c + a;
	cout << c << endl;

	c = c + 2.5;
	cout << c << endl;

	c = 2.5 + c;
	cout << c << endl;

	c -= a;
	cout << c << endl;

	c = c - a;
	cout << c << endl;

	c = c - 2.5;
	cout << c << endl;

	c = 2.5 - c;
	cout << c << endl;

	c *= b;
	cout << c << endl;

	c = c * b;
	cout << c << endl;

	c = c * 2.5;
	cout << c << endl;

	c = 2.5 * c;
	cout << c << endl;

	c /= b;
	cout << c << endl;

	c = c / b;
	cout << c << endl;

	c = c / 2.5;
	cout << c << endl;

	c = 2.5 / c;
	cout << c << endl;

	c = a + 2.5 + a + b*2.5*b;
	cout << c << endl;

	c = -b;
	cout << c << endl;

	cout << (a == a) << endl; //output 1
	cout << (a == 0.0) << endl; //output 1
	cout << (0.0 == a) << endl; //output 1
	cout << (a != a) << endl; //output 0 
	cout << (a != 0.0) << endl; //output 0
	cout << (0.0 != a) << endl; //output 0  

	cin >> c; //输入格式(a,b)表示复数a + b i
	cout << c << endl;
}

int main()
{
	f();
    return 0;
}

