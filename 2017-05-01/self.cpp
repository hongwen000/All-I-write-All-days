#include <iostream>

using namespace std;

int main() 
{
    int *p;
    p = reinterpret_cast<int*>(&p);
    cout << (int*)p << endl;
    cout << (int*)*p << endl;
    p = reinterpret_cast<int*>(*p);
    cout << (int*)p << endl;
    cout << (int*)*p << endl;

    return 0;
}
