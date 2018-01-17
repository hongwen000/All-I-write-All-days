#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int inst = 0;
vector<int> quickSort(vector<int> s, int level)
{
    cout << "level:" << level << endl;
    cout << "instance:" << inst++ << endl;
    for_each(s.begin(), s.end(), [](auto i){cout << i << ", ";});
    cout << endl << endl;
    if(s.size() == 0) return vector<int>{};
    if(s.size() == 1) return vector<int>{s[0]};
    vector<int> l, g;
    std::copy_if(s.begin() + 1, s.end(), std::back_inserter(l), [&s](auto i){return i < s[0];});
    std::copy_if(s.begin() + 1, s.end(), std::back_inserter(g), [&s](auto i){return i >= s[0];});
    l = quickSort(l, level + 1);
    g = quickSort(g, level + 1);
    vector<int> ret = l;
    ret.insert(ret.end(), s[0]);
    ret.insert(ret.end(), g.begin(), g.end());
    return ret;
}
int main()
{
    vector<int> s{54, 37, 93, 25, 17, 68, 58, 41, 76};
    auto ret = quickSort(s, 1);
    for_each(ret.begin(), ret.end(), [](auto i){cout << i << ' ';});
}
