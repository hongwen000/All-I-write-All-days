#include "meta.h"
#include <string>
#include <vector>
using namespace std;
class A : public base {
    public:
    A() {
        addWatch();
    }
    private:
    DECLARE(string, s);
    DECLARE(int, i);
    void addWatch() {
        WATCH(A, s);
        WATCH(A, i);
    }
};

class B : public base {
    public:
        B() {
            addWatch();
        }
    private:
        DECLARE(A, a);
        DECLARE(vector<int>, v);
        void addWatch() {
            WATCH(B, a);
            WATCH(B, v);
        }
};
int main()
{
    A a;
    a.set_s("hhh");
    a.set_i(100);
    B b;
    b.set_a(a);
    b.get_v() = vector<int>{1, 2, 3, 5};
    b.print();
}
