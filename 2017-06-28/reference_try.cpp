#include <iostream>
using namespace std;
int& r = *(new int(1));
int main()
{
    cout << r << endl;
    r = 2;
    cout << r << endl;
    int i(0);
}
