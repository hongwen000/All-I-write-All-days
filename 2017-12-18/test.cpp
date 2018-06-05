#include "tree.cpp"
#include <gtest/gtest.h>
#include <numeric>
using namespace std;

int sum_force(int a[], int L, int R)
{
    int ret = 0;
    for(int i = L; i <= R; ++i)
    {
        ret += a[i];
    }
    return ret;
}

TEST(test, test_sum)
{
    srand(time(0));
    int n = 1000;
    int m = 5000;
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 10000;
    }
    auto t = build(a, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int ty = rand() % 2;
        int x, y;
        if (ty == 0) {
            x = rand() % n;
            y = rand() % n;
            if (x > y)
                swap(x, y);
            EXPECT_EQ(sum_force(a, x, y), sum(t, x, y));
        }
        else {
            x = rand() % n;
            y = rand() % 10000;
            change(t, x, y);
        }
    }
}

int main(int argc, char ** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
