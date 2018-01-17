#include <iostream>
#include <algorithm>
#include <vector>
#include <gtest/gtest.h>
using namespace std;

size_t parent(size_t n)
{
    return n / 2;
}

size_t left(size_t n)
{
    return 2 * n + 1;
}

size_t right(size_t n)
{
    return 2 * n + 2;
}


void adjust(vector<int>& v, size_t k, size_t n)
{
    auto lch = left(k);
    auto rch = right(k);
    auto lg = k;
    if(rch < n && v[lg] < v[rch])
        lg = rch;
    if(lch < n && v[lg] < v[lch])
        lg = lch;
    if(v[k] < v[lg]) {
        swap(v[k], v[lg]);
        adjust(v, lg, n);
    }
}

vector<int> build_heap(const vector<int>& v)
{
    vector<int> s = v;
    int n = v.size();
    for(int i = (n - 1)/ 2; i >= 0; --i) {
        adjust(s, i, v.size());
    }
    return s;
}

vector<int> heap_sort(const vector<int>& v)
{
    auto s = v;
    int n = v.size();
    for(int i = n - 1; i > 0; --i) {
        swap(s[i], s[0]);
        adjust(s, 0, --n);
    }
    return s;
}

vector<int> force(const vector<int>& v)
{
    auto s = v;
    std::sort(s.begin(), s.end());
    return s;
}

TEST(test, test)
{
    srand(time(0));
    int n = rand() % 20;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 5000);
    }
    auto hp = build_heap(v);
    EXPECT_EQ(heap_sort(hp), force(v));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

