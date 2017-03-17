#include <iostream>
using namespace std;
int main ()
{
long double pi=0;
int factor=1;
for (long int i=1;;i++)
{
pi=4×（factor/(2*i+1));
factor = -factor;
cout << pi <<endl;
}
return 0;
}
