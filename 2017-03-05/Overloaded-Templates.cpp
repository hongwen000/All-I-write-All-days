#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T> string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return "First Template: " + ret.str() + "; ";
}
template <typename T> string debug_rep(T *p)
{
    ostringstream ret;
    ret << "point: " << p << "; ";
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return "Second Template: " + ret.str();
}

string debug_rep(const string &s)
{
    return "Nontemplate: \"" + s + "\";";
}

string debug_rep(const char *p)
{
    cout << "Notemplate char * : ";
    return debug_rep(string(p));
}

int main()
{
    string s("hi");
    cout << debug_rep(s) << endl;
    cout << debug_rep(&s) << endl;
    const string *sp = &s;
    cout << debug_rep(sp) << endl;
    cout << debug_rep("hi")<<endl;
    return 0;
}
