#include <iostream>

using namespace std;
int sumDigits(long n)
{
if(n/10>0)
{
    return n%10+sumDigits(n/10);
}
else
    return n;
}

int main()
{
    cout << sumDigits(234) << endl;
    return 0;
}
