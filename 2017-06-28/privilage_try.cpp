#include <iostream>
using namespace std;
class base {
    private:
        void b_private() { cout << "base private" << endl; } 
    protected:
        void b_protected() { cout << "base protected" << endl; }
    public:
        void b_public() { cout << "base public" << endl; }
};

class public_derived : public base {
    friend void f();
    void g() {
    }
};

void f() {
    public_derived pdo;
    pdo.b_protected();
}
class protected_derived : protected base {
};

class private_derived : private base {
};

int main()
{
    f();    
}
