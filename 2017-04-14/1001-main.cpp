#include <iostream>
using namespace std;


class Complex
{
public:
	Complex(int a=0, int b=0): real(a), imag(b) {}
	friend Complex operator*(const Complex&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
	friend ostream& operator<<(ostream&, const Complex&);

private:
	int real;
	int imag;
};

#include "1001.h"

int main()
{
	//freopen("test01.in", "r", stdin);
	//freopen("test01.out", "w", stdout);
	int t;
	cin>>t;
	while(t--) {
		Complex a, b;
		cin >> a>> b;
		cout << a * b << endl; 
	}

	return 0;
}
