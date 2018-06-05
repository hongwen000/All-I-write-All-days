#include <type_traits>
#include <iostream>
using namespace std;
template<typename T>
remove_pointer_t<T>& at(T const& a, size_t i)
{
    return a[i];
}
template<typename T>
void f(T a)
{
    std::cout << typeid(a).name() << std::endl;
}
template<typename T>
class P {
    public:
        static int i;
};
template<> int P<int>::i = 1;
template<int N>
class X {
    public:
    typedef int I;
    void f(int) {
        
    }
};
template<int N>
//void fppm(void (*) (typename X<N>::I)); 
//Error: Cannot deduce N 
void fppm(void (X<N>::*p) (typename X<N>::I));
//the X<N> part of the sub-construct X<N>::*p help deduce N

int main()
{
    //fppm(&X<33>::f);
    f(P<int>::i);
}
