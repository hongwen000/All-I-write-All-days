#include <iostream>
using namespace std;
template<unsigned n>
struct Factorial {
    const static long value = n * Factorial<n - 1>::value;
};
template<>
struct Factorial<0> {
    const static long value = 1;
};
int main()
{
    cout << Factorial<20>::value << endl;
    return 0;
}
