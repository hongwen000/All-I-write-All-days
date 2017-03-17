#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
class Rational
{
public:
	Rational();
	Rational(long numerator, long denominator);
	long getNumerator();
	long getDenominator();
	Rational add(Rational &secondRational);
	Rational subtract(Rational &secondRational);
	Rational multiply(Rational &secondRational);
	Rational divide(Rational &secondRational);
	/* Returns an int value -1, 0, or 1 to indicate whether this rational
	number is less than, equal to, or greater than the specified number.
	*/
	int compareTo(Rational &secondRational);
	bool equals(Rational &secondRational);
	int intValue(); //Returns the numerator/denominator
	double doubleValue(); //Returns 1.0*numberator/denominator
	string toString();
	bool operator<(Rational &secondRational);
	bool operator<=(Rational &secondRational);
	bool operator>(Rational &secondRational);
	bool operator>=(Rational &secondRational);
	bool operator!=(Rational &secondRational);
	bool operator==(Rational &secondRational);
	Rational operator+(Rational &secondRational);
	Rational operator-(Rational &secondRational);
	Rational operator*(Rational &secondRational);
	Rational operator/(Rational &secondRational);
	Rational operator+=(Rational &secondRational);
	Rational operator-=(Rational &secondRational);
	Rational operator*=(Rational &secondRational);
	Rational operator/=(Rational &secondRational);
	long& operator[](const int &index);
	Rational operator++();
	Rational operator--();
	Rational operator++(int dummy);
	Rational operator--(int dummy);
	Rational operator+();
	Rational operator-();
	friend ostream &operator<<(ostream &stream, Rational &rational);
	friend istream &operator>>(istream &stream, Rational &rational);
	operator double();

private:
	long numerator; //分子. 
	long denominator; //分母，不能为0. 
	static long gcd(long n, long d);
};
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}
int Rational::compareTo(Rational & secondRational)
{
	// TODO Auto-generated method stub
	if (this->subtract((secondRational)).getNumerator() > 0) {
		return 1;
	}
	else if (this->subtract((secondRational)).getNumerator() < 0) {
		return -1;
	}
	else {
		return 0;
	}
}
bool Rational::equals(Rational & secondRational)
{
	if ((this->subtract(secondRational)).getNumerator() == 0) {
		return true;
	}
	else {
		return false;
	}
}
int Rational::intValue()
{
	return numerator / denominator;
}
double Rational::doubleValue()
{
	return 1.0*numerator / denominator;
}
string Rational::toString()
{
	char s[50];
	if (denominator == 1) {
		sprintf_s(s, "%ld", numerator);
	}
	else {
		sprintf_s(s, "%ld/%ld", numerator, denominator);
	}
	return string(s);
}
Rational  Rational::add(Rational &secondRational) {
	long n = numerator * secondRational.getDenominator() + denominator
		* secondRational.getNumerator();
	long d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}
Rational  Rational::subtract(Rational &secondRational) {
	long n = numerator * secondRational.getDenominator() - denominator
		* secondRational.getNumerator();
	long d = denominator * secondRational.getDenominator();
	return Rational(n, d);
}
Rational  Rational::multiply(Rational &secondRational) {

	long n = numerator * secondRational.getNumerator();
	long d = denominator * secondRational.getDenominator();
	return  Rational(n, d);
}
Rational  Rational::divide(Rational &secondRational) {

	long n = numerator * secondRational.getDenominator();
	long d = denominator * secondRational.getNumerator();
	return  Rational(n, d);
}
long Rational::gcd(long n, long d)
{
	long n1 = abs(n);
	long n2 = abs(d);
	long remainder = n1 % n2;
	while (remainder > 0) {
		n1 = n2;
		n2 = remainder;
		remainder = n1 % n2;
	}
	return n2;
}
Rational::Rational(long numerator, long denominator)
{
	long gcd1 = gcd(numerator, denominator);
	this->numerator = (denominator > 0 ? 1 : -1) * numerator / gcd1;
	this->denominator = abs(denominator) / gcd1;
}
long Rational::getNumerator()
{
	return numerator;
	return 0;
}
long Rational::getDenominator()
{
	return denominator;
}
bool Rational::operator<(Rational &secondRational)
{
	return (this->compareTo(secondRational) < 0);
}
bool Rational::operator<=(Rational &secondRational)
{
	return (this->compareTo(secondRational) <= 0);
}
bool Rational::operator>(Rational &secondRational)
{
	return (this->compareTo(secondRational) > 0);
}
bool Rational::operator>=(Rational &secondRational)
{
	return (this->compareTo(secondRational) >= 0);
}
bool Rational::operator!=(Rational &secondRational)
{
	return (this->compareTo(secondRational) != 0);
}
bool Rational::operator==(Rational &secondRational)
{
	return (this->compareTo(secondRational) == 0);
}
Rational Rational::operator+(Rational &secondRational)
{
	return this->add(secondRational);
}
Rational Rational::operator-(Rational &secondRational)
{
	return this->subtract(secondRational);
}
Rational Rational::operator*(Rational &secondRational)
{
	return this->multiply(secondRational);
}
Rational Rational::operator/(Rational &secondRational)
{
	return this->divide(secondRational);
}
Rational Rational::operator+=(Rational &secondRational)
{
	*this = this->add(secondRational);
	return (*this);
}
Rational Rational::operator-=(Rational &secondRational)
{
	*this = this->subtract(secondRational);
	return (*this);
}
Rational Rational::operator*=(Rational &secondRational)
{
	*this = this->multiply(secondRational);
	return (*this);
}
Rational Rational::operator/=(Rational &secondRational)
{
	*this = this->divide(secondRational);
	return *this;
}
long& Rational::operator[](const int &index)
{
	if (index == 0)
		return numerator;
	else if (index == 1)
		return denominator;
	else
	{
		cout << "subscript error" << endl;
		exit(0);
	}
}
Rational Rational::operator++()
{
	numerator += denominator;
	return *this;
}
Rational Rational::operator--()
{
	numerator -= denominator;
	return *this;
}
Rational Rational::operator++(int dummy)
{
	Rational temp(numerator, denominator);
	numerator += denominator;
	return temp;
}
Rational Rational::operator--(int dummy)
{
	Rational temp(numerator, denominator);
	numerator -= denominator;
	return temp;
}
Rational Rational::operator+()
{
	return *this;
}
Rational Rational::operator-()
{
	numerator *= -1;
	return *this;
}
Rational::operator double()
{
	return doubleValue();
}
istream &operator>>(istream &str, Rational &rational)
{
	cout << "Enter numerator: ";
	str >> rational.numerator;
	cout << "Enter denominator: ";
	str >> rational.denominator;
	return str;
}
ostream& operator<<(ostream &str, Rational &rational)
{
	cout << rational.toString();
	return str;
}

int main()
{
	// Create and initialize two rational numbers r1 and r2.
	Rational r1(4, 2);
	Rational r2(2, 3);
	// Test relational operators
	cout << r1 << " > " << r2 << " is " << (r1 > r2) << endl;
	cout << r1 << " < " << r2 << " is " << (r1 < r2) << endl;
	cout << r1 << " == " << r2 << " is " << (r1 == r2) << endl;
	cout << r1 << " != " << r2 << " is " << (r1 != r2) << endl;
	// Test toString, add, substract, multiply, and divide operators
	cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
	cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;
	cout << r1 << " * " << r2 << " = " << r1 * r2 << endl;
	cout << r1 << " / " << r2 << " = " << r1 / r2 << endl;
	// Test shorthand operators
	Rational r3(1, 2);
	r3 += r1;
	cout << "r3 is " << r3 << endl;
	// Test function operator []
	Rational r4(1, 2);
	r4[0] = 3; r4[1] = 4;
	cout << "r4 is " << r4 << endl;
	// Test function operators for prefix ++ and --
	r3 = r4++;
	cout << "r3 is " << r3 << endl;
	cout << "r4 is " << r4 << endl;
	// Test function operator for conversion
	cout << "1 + " << r4 << " is " << (1 + r4) << endl;
	return 0;
}