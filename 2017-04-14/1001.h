#ifndef H_COMPLEX_H
#define H_COMPLEX_H
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <vector>

using namespace std;

pair<int,int> pickUp(string s) {
    regex regex_real(R"(.+(?=[\+\-]))");
    regex regex_imag("(?=[\\+\\-]).*(?=i)");
    smatch result_real;
    smatch result_imag;
    pair<int,int> rst;
    if (regex_search(s, result_real, regex_real)) {
        stringstream ssr(result_real.str());
        ssr >> rst.first;
    }
    if (regex_search(s, result_imag, regex_imag)) {
        string si = result_imag.str();
        stringstream ssi(si.substr(1));
        ssi >> rst.second;
        if(si[0] == '-') 
            rst.second = - rst.second;
    }
    return rst;
}

Complex operator*(const Complex & s1, const Complex & s2) {
	Complex temp;
	temp.real = s1.real * s2.real - s1.imag * s2.imag;
	temp.imag = s1.imag * s2.real + s1.real * s2.imag;
	return temp;
}

istream& operator>>(istream& in, Complex& cpx)
{
    string s;
    in >> s;
    pair<int,int> rst = pickUp(s);
    cpx.real = rst.first;
    cpx.imag = rst.second;
	return in;
}

ostream& operator<<(ostream& out, const Complex& s)
{
	(s.imag > 0 || s.imag == 0) ? out << s.real << "+" << s.imag << "i" : out << s.real << s.imag << "i";
	return out;
}

#endif
