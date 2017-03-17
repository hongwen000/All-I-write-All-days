#include <iostream>

using namespace std;
double m(int i)
{
if (i>1)
{
    return 1.0/i + m(i-1.0);
}
else
    return 1;
}

int main()
{
    cout << m(10) << endl;
    return 0;
}
