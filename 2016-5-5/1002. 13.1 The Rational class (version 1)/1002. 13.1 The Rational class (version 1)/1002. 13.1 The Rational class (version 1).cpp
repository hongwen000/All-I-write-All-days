// 1002. 13.1 The Rational class (version 1).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
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
		sprintf(s, "%ld", numerator);
	}
	else {
		sprintf(s, "%ld/%ld", numerator, denominator);
	}
	return string(s);
}
Rational  Rational:: add(Rational &secondRational) {
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

int main()
{
    return 0;
}

