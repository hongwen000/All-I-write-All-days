#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    int a(1);
//    auto b = {1};
//    cout << typeid(b).name() << endl;
//    b == 1;
    auto c = {1};
    cout << typeid(c).name() << endl;
    return 0;
}
