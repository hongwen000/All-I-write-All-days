#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <map>
#include <random>
using namespace std;
int main() {
    map<int, int> mp;
    auto cmp = [&](int t1, int t2) {
        mp[t1] = 1;
        mp[t2] = 1;
        return t1 > t2;
    };
    std::vector<int> v;
    for(int i = 0; i < 20; ++i) {
        v.push_back(i);
    }
    std::default_random_engine rd(0);
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    std::sort(v.begin(), v.end(), cmp);
    for(auto i : mp) {
        cout << i.first << ' ' << i.second << std::endl;
    }
}
