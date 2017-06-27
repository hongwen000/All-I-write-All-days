#include <typeinfo>
#include <iostream>
using namespace std;
class A {
public:
    virtual ~A(){}
};
class B : public A {
};
class C : public B {
};
class D : public B, public A {
};
int main()
{
    A* pa0 = new C;
    B* pb0 = dynamic_cast<B*>(pa0);
    cout << (pb0 ? true : false) << endl;
    B* pa1 = new B;
    C* pb1 = dynamic_cast<C*>(pa1);
    cout << (pb1 ? true : false) << endl;
//    A* pa2 = new D;
//    B* pb2 = dynamic_cast<B*>(pa2);
//    cout << (pb2 ? true : false) << endl;
    auto p = D{};
    cout << typeid(p).name() <<endl;
}

