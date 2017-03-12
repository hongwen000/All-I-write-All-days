#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

template <typename T> string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return "First Template: " + ret.str() + "; \n";
}

template<typename T>
ostream &print(ostream &os, const T &t)
{
    return os << t;
}
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest)
{
    cout << "Args: " << sizeof...(Args) << endl;
    cout << "rest: " << sizeof...(rest) << endl;
    os << t << endl;
    return print(os, rest...);
}

template <typename...Args>
ostream &errorMsg(ostream &os, const Args&...rest)
{
    return print(os, debug_rep(rest)...) << endl;
}
string debug_rep(const char *p)
{
    cout << "Notemplate char * : ";
    return debug_rep(string(p));
}
int main()
{
    errorMsg(cout, string("ha1"), string("ha2"), string("ha3"), string("ha4"));
    return 0;
}
