#include <iostream>

using namespace std;
long factorial(int n)
{
if(n >1)
    return n*factorial(n-1);
else
    return 1;
}
int main()
{
    cout << factorial(5) << endl;
    return 0;
}
