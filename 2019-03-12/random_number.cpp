#include <iostream>
#include <time.h>
#include <random>
using namespace std;
void knuth(int n, int m)
{
    srand((unsigned int) time(0));
    for(int i = 0; i < n; ++i)
    {
        if(rand() % (n-i) < m) {
            cout << i << endl;
            m--;
        }
    }
}
int main()
{
    knuth(100000,5);
}