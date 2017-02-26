static int counter = 0;
#include <iostream>
using namespace std;
int f()
{
    cout << counter << " times enter f()" << endl;
    counter++;
    void * ptr = NULL;
    return 0;
}
int main()
{
    f();
    return 0;
}
