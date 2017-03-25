#define DEBUG 0
#include <iostream>
using namespace std;
int main()
{
#if DEBUG
    cout << " on debug " << endl;
    return 0;
#endif
}
