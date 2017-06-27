#include <iostream>
using namespace std;

class a {
};
class b {
};
class c : public a {
    virtual void fun() = 0;
};
class d : public b, public c {
};
class e {
    virtual void fun() = 0;
};
int main()
{
    cout << "sizeof(a)" << sizeof(a) << endl;
    cout << "sizeof(b)" << sizeof(b) << endl;
    cout << "sizeof(c)" << sizeof(c) << endl;
    cout << "sizeof(d)" << sizeof(d) << endl;
    cout << "sizeof(e)" << sizeof(e) << endl;
    return 0;
}
