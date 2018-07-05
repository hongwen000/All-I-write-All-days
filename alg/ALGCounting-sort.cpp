#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <type_traits>
using namespace std;
#include <gtest/gtest.h>
vector<int> counting_sort(const vector<int>& A, int k)
{
    vector<int> B(A.size());
    vector<int> C(k, 0);
    for(auto i : A) C[i]++;
    for(size_t i = 1; i < C.size(); ++i) C[i] = C[i] + C[i-1];
    for (auto i : A) {
        B[C[i]] = i;
        C[i] = C[i] - 1;
    }
    return B;
}
int main(int argc, const char *argv[])
{
    vector<int> A;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        A.push_back(rand() % 10);
    }
    for (auto i : counting_sort(A, 10)) {
        std::cout << i << '\t';
    }
    return 0;
}
