#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void insert(vector<int> &v, size_t k)
{
    vector<int>::iterator pos = std::upper_bound(v.begin(), v.begin() + k, v[k]);
    v.insert(pos, v[k]);
    v.erase(v.begin() + k + 1);
}
int main()
{
    std::vector<int> v{1, 3, 5, 6, 0, 1, 2};
    insert(v, 4);
    for(auto i : v)
        cout << i << endl;
}
