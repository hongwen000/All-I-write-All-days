#include <iostream>
#include <vector>
using namespace std;
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    return *beg;
}
int main()
{
    vector<int> a = {1, 2, 3};
    cout << fcn(a.begin(), a.end()) << endl;
    return 0;
}
