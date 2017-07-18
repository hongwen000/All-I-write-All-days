#include <iostream>
using namespace std;
class Base
{
    public:

        Base(int i) :baseI(i){};

        virtual void print(void){ cout << "调用了虚函数Base::print()"; }

        virtual void setI(){cout<<"调用了虚函数Base::setI()";}

        virtual ~Base(){}

    private:

        int baseI;
};
int main()
{
    using vtable_ptr_type = int *;
    using vtable_address_type = int *;
    Base b(1000);
    vtable_ptr_type vtable_ptr = (int *)(&b);
    cout << "虚函数指针（vprt）的地址是：\t"<<vtable_ptr << endl;
    typedef void(*Fun)(void);
    vtable_address_type vtable_address = (vtable_address_type)*(vtable_ptr); 
    Fun vfunc = (Fun)*(vtable_address);
    cout << "第一个虚函数的地址是：" << vtable_address << endl;
    cout << "通过地址，调用虚函数Base::print()：" << endl;
    vfunc();
    cout << endl;
    auto vfun2 = ( (int * )(*(int*)(&b)+1));
    cout << "第二个虚函数的地址是：" << vfun2 << endl;
    ((Fun)*(vfun2))();
}
