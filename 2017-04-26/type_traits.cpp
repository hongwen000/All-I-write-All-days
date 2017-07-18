#include <iostream>
using namespace std;

struct B_tag {};
struct D1_tag : B_tag {};
struct D2_tag : D1_tag {};

template <class T>
struct my_traits {
    using category = typename T::category;
};

template <class T>
struct my_traits<T*> {
    using category = T;
};

template <class T>
struct my_traits<const T*> {
    using category = T;
};

struct B {
    using category = B_tag;
};

struct D1 {
    using category = D1_tag;
};

struct D2 {
    using category = D2_tag;
};


template <class T>
void func(T a) {
    using category = typename my_traits<T>::category;
    __func(a, category());
}

template <class T>
void __func(T, B_tag) {
    cout << "B_tag" << endl;
}

template <class T>
void __func(T, D2_tag) {
    cout << "D2_tag" << endl;
}



int main() 
{
    B B_obj;
    D1 D1_obj;
    D2 D2_obj;
    func(B_obj);
    func(D1_obj);
    func(D2_obj);
    return 0;
}
    


