#include <iostream>
using namespace std;
void prim(int m, int n)
{
    if(m >= n)
    {
        while(m%n) n++;
        m/=n;
        prim(m, n);
        cout << n << endl; 
    }
}

int main()
{
    prim(1000,2);
}
