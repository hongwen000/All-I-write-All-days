#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int array[3][4][5];
    cout << typeid(array).name()<<endl;
    return 0;
}
