#include <iostream>
using namespace std;

class C {
    public:
        void m();
};
void C::m()
{
    static int s = 0;
    cout << ++s << endl;
}
int main()
{
    C c1;
    C::s = 1;
    return 0;
}
