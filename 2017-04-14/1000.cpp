#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

class A {
    public:
        A(int _x, string _s) { 
            px = new int(_x);
            s = _s;
            cout << "constructing A" << endl;
            }

        A(const A& rhs) {
            int rx = *rhs.px;
            px = new int(rx);
            s = rhs.s;
            cout << "copying A" << endl;
        }

        A& operator==(const A& rhs) {
            if(this == &rhs)
                return *this;
            int rx = *rhs.px;
            int* tmp = new int(rx);
            delete px;
            px = tmp;
            cout << "assigning A" << endl;
        }
        
        void setX(int _x) {
            *px = _x;
        }
    private:
        string s;
        int* px;
};

int main()
{
    A obj1(1, "obj");
    A obj2 = obj1;
    obj2.setX(2);
    return 0;
}
