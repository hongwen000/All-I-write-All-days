#include <string>
#include <iostream>
class A{};
using namespace std;
int main()
{
    struct s1 {
        void f() { cout << "最外层" << endl; };
        struct s2 {
            void f(int) { cout << "第二层" << endl; }
                struct s3 {
                    void f(A) { cout << "最内层" << endl; }
                };
        };
    };
    s1 u1;
    s1::s2 u2;
    s1::s2::s3 u3;
    u1.f();
    u1.f(1);
    u1.f(cout);
    u2.f();
    u2.f(1);
    u2.f(A());
    u3.f();
    u3.f(1);
    u3.f(A());
    return 0;
}
