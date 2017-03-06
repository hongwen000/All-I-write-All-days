#include <iostream>
using namespace std;
int main(int a)
{
    if(a==0)
    {
        return 1;
    }
    else 
    {
        return main(a-1)*a;
    }
}
