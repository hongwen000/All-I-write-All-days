#include "jjalloc.h"
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int ia[5] = {0, 1, 2, 3, 4};
    vector<int, JJ::allocator<int>> iv(ia, ia + 5);
    for(int i : iv)
        cout << i << endl;
    return 0;
}
