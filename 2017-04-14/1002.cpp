#include <iostream>
#include <string>
using namespace std;

class Complex {
public:
    Complex(int a = 0, int b = 0)
        : real(a)
        , imag(b)
    {
    }
    friend Complex operator*(const Complex&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
    friend ostream& operator<<(ostream&, const Complex&);

private:
    int real;
    int imag;
};

Complex operator*(const Complex& a, const Complex& b)
{
    Complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + b.real * a.imag;
    return c;
}

istream& operator>>(istream& is, Complex& a)
{
    string x; //把is中的字符提取到x中；
    is >> x;
    string y = "+";
    string z = "-";
    int num = 0;
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    int result4 = 0;
    int len = x.size();
    if (x.find(y) != -1) // find 函数 返回第二个字符所在的位置
    {
        num = x.find(y);
        for (int i = 0; i < num; ++i) {
            result1 = result1 * 10 + (x[i] - '0');
        }
        a.real = result1;
        for (int i = num + 1; i < len - 1; ++i) {
            result3 = result3 * 10 + (x[i] - '0');
        }
        a.imag = result3;
    } else {
        num = x.find(z);
        for (int i = 0; i < num; ++i) {
            result2 = result2 * 10 + (x[i] - '0');
        }
        a.real = result2;
        for (int i = num + 1; i < len - 1; ++i) {
            result4 = result4 * 10 + (x[i] - '0');
        }
        a.imag = - result4;
    }
    return is;
}

ostream& operator<<(ostream& os, const Complex& a)
{
    if (a.imag >= 0)
        os << a.real << "+" << a.imag << "i";
    else
        os << a.real << a.imag << "i";
    return os;
}

int main()
{
    //freopen("test01.in", "r", stdin);
    //freopen("test01.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        Complex a, b;
        cin >> a >> b;
        cout << a * b << endl;
    }
    return 0;
}
