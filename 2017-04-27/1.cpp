#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> a(10);
    uninitialized_fill_n(a.begin(), 10, 5);
    vector<int> b(10);
    uninitialized_copy(a.begin(), a.end(), b.begin());
    for(int x : b)
        cout << x << endl;
    return 0;
}

