#ifndef H_COMPLEX_H
#define H_COMPLEX_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class complex
{
	double re; //real part of a complex number
	double im; //imaginary part of a complex number
public:
	double real() const { return re; }
	double imag() const { return im; }
	// add any other function needed here
	friend ostream& operator<<(ostream& out, const complex& s);
	complex()
	{
		re = 0;
		im = 0;
	}
	double getModuli() {
		return sqrt(pow(re,2) + pow(im,2));
	}
	complex(double _re)
	{
		re = _re;
		im = 0;
	}
	complex(double _re, double _im)
	{
		re = _re;
		im = _im;
	}
	complex(const complex & s)
	{
		re = s.re;
		im = s.im;
	}
	complex& operator +=(const complex &s)
	{
		re += s.re;
		im += s.im;
		return *this;
	}
	complex& operator -=(const complex &s)
	{
		re -= s.re;
		im -= s.im;
		return *this;
	}
	complex& operator *=(const complex &s)
	{
		complex temp(*this);
		re = temp.re * s.re - temp.im * s.im;
		im = temp.im * s.re + temp.re * s.im;
		return *this;
	}
	complex& operator /=(const complex &s)
	{
		complex temp(*this);
		re = (temp.re*s.re + temp.im*s.im) / (pow(s.re, 2) + pow(s.im, 2));
		im = (temp.im*s.re - temp.re*s.im) / (pow(s.re, 2) + pow(s.im, 2));
		return *this;
	}
	friend complex operator + (const complex & s1, const complex &s2);
	friend complex operator - (const complex & s1, const complex &s2);
	friend complex operator * (const complex & s1, const complex &s2);
	friend complex operator / (const complex & s1, const complex &s2);
	complex operator - ()
	{
		complex temp;
		temp.re = -(this->re);
		temp.im = -(this->im);
		return temp;
	}
	friend int operator == (const complex & s1, const complex &s2);
	friend int operator != (const complex & s1, const complex &s2);
	friend istream& operator >> (istream &in, complex &s);
	void display() {
		cout << *this;
	}
};
#endif