#include "complex.hpp"
ostream& operator<<(ostream& out, const complex& s)
{
	if (s.re == 0 && s.im == 0)
		out << 0;
	else if (s.re == 0)
		out << s.im << "i";
	else if (s.im == 0)
		out << s.re;
	else
		s.im > 0 ? out << s.re << "+" << s.im << "i" : out << s.re << s.im << "i";
	//out << "(" << s.re << "," << s.im<<")";
	return out;
}

complex operator+(const complex & s1, const complex & s2)
{
	complex temp;
	temp.re = s1.re + s2.re;
	temp.im = s1.im + s2.im;
	return temp;
}
complex operator-(const complex & s1, const complex & s2)
{
		complex temp;
		temp.re = s1.re - s2.re;
		temp.im = s1.im - s2.im;
		return temp;
}
complex operator*(const complex & s1, const complex & s2)
{
	complex temp;

	temp.re = s1.re * s2.re - s1.im * s2.im;
	temp.im = s1.im * s2.re + s1.re * s2.im;
	return temp;
}
complex operator/(const complex & s1, const complex & s2)
{
	complex temp;
	temp.re = (s1.re*s2.re + s1.im*s2.im) / (pow(s2.re, 2) + pow(s2.im, 2));
	temp.im = (s1.im*s2.re - s1.re*s2.im) / (pow(s2.re, 2) + pow(s2.im, 2));
	return temp;
}
int operator==(const complex & s1, const complex & s2)
{
	if (s1.re == s2.re && s1.im == s2.im)
		return 1;
	else
		return 0;
}
int operator!=(const complex & s1, const complex & s2)
{
	if (s1.re != s2.re || s1.im != s2.im)
		return 1;
	else
		return 0;
}
istream & operator>>(istream & in, complex &s)
{
	char a;
	in >> a >> s.re >> a >> s.im >> a;
	return in;
}