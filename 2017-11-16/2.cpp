#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
set<int> a{1,2};
set<int> b{2,3};
set<int> c;
int main() {
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));
    for(auto& i : c)
        cout << i << endl;
}
