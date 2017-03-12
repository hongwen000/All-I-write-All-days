#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

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

class A { };
int main()
{
    A obj;
    print(cout, 41, 42, 43, 44, 45) << endl;
    print(cout, obj); 
    return 0;
}
