#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int uniquify(vector<int>& v) {
    std::sort(v.begin(), v.end());
    int i = 0, j = 0;
    while(++j < v.size())
        if(v[i] != v[j])
            v[++i] = v[j];
    return ++i;
}

int binSearch(vector<int>& v, int e, int lo, int hi) {
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(v[mid] == e)
            return mid;
        else if (v[mid] > e)
            hi = mid;
        else
            lo = mid + 1;
    }
    return -1;
}

int main() {
    vector<int> a{ 1, 2 ,34, 45, 6,7};
    std::cout << binSearch(a, 6, 0, a.size()) << std::endl;
    std::cout << a[binSearch(a, 6, 0, a.size())] << std::endl;
    int N = 100;
    vector<int> v;
    srand(time(0));
    for(int i = 0; i < N; ++i) {
        v.push_back(rand() % (N / 3 * 2));
    }
    vector<int> vp = {1,1,1,1,1};
    int p = uniquify(vp);
    for(int i = 0; i < p; ++i) {
//        std::cout << vp[i] << ' ';
    }
}
