#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <random>
#include <functional>
using std::vector;
vector<int>merge(const vector<int>& u, const vector<int>& v) {
    vector<int> dst;
    std::merge(u.cbegin(), u.cend(), v.cbegin(), v.cend(), std::back_inserter(dst));
    return dst;
}
int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> dis(0, 9);
    std::vector<int> v1(10), v2(10);
    std::generate(v1.begin(), v1.end(), std::bind(dis, std::ref(mt)));
    std::generate(v2.begin(), v2.end(), std::bind(dis, std::ref(mt)));
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    auto ret = merge(v1, v2);
    for(auto i : ret)
        std::cout << i << std::endl;
}
