#include <iostream>
using namespace std;
struct X {
    int f() {return 1;};
    friend int f() { return 0; }
    X() { f(); }
    int g();
    int h();
};
int X::g() { return f(); }
int f();
int X::h() {return f(); }
int main()
{
    X obj;
    cout << obj.g() << endl;
    return 0;
}
