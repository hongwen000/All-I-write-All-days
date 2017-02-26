#include <iostream>
#include <algorithm>
using namespace std;
class X
{
    public:
        int *p;
        X& operator=(X const & rhs)
        {
            if(p!=0)
            delete p;
            p=new int;
            *p=*(rhs.p);
            cout <<" '=' construct"<<endl; 
            return *this;
        }
        X(int i)
        {
            p=new int;
            *p=i;
            cout <<"Default construct"<<endl;
        }
        X(X const &rhs)
        {
            p=new int;
            *p=*(rhs.p);
            cout <<"Lvalue copy construct"<<endl;
        }
        X(X &&rhs)
        {
            cout <<"Rvalue copy construct"<<endl;
           swap(this->p,rsh.p);
           return *this;
        } 
        ~X()
        {
            delete p;
            cout <<"Deconstruct"<<endl;
        }
};
X foo1()
{
    cout <<"foo1,controversal"<<endl;
    X  x1(1);
    return x1;
}

int main()
{
//    X X1(1);
//    X X2(X1);
//    X X3=X2;
    X x=foo1(); 
    cout <<*(x.p)<<endl;
    return 0;
}


