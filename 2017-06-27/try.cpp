#include <iostream>
using namespace std;
template <class T>
class base {
    public:
        void show(T obj) {
            cout << obj << endl;
        }
};

template <class T, class U>
class derived:public base<U> {
    public:
        void show(T obj1, U obj2) {
            cout << obj1 << endl;
            base<U>::show(obj2);
        }
};


