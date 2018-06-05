#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> s;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        s.push_back(t);
    }
    int k, x;
    cin >> k >> x;
    for (auto &i :s) {
        i -= x;
    }
    std::sort(s.begin(), s.end());
    std::stable_sort(s.begin(), s.end(), [](auto lhs, auto rhs){return abs(lhs) < abs(rhs);});
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        ans.push_back(s[i] + x);
    }
    std::sort(ans.begin(), ans.end());
    stringstream ss;
    for (auto i : ans) {
        ss << i << ' ';
    }
    auto str = ss.str();
    cout << str.substr(0, str.size() - 1);
}
