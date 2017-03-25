#include <iostream>
using namespace std;
class A {
    public:
        int *a;
        A() : a(new int) { }
        A(const A& const r) {
            a = new int;
            *r.a = 2;
        }
        ~A() { delete a; }
};
int main()
{
    A obj1;
    A obj2(obj1);
    cout << *obj1.a << endl;
    return 0;
}

