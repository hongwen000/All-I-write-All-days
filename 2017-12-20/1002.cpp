#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <numeric>
#include <climits>
using namespace std;
int getSum(vector<int> s, int x)
{
    if(s.size() <= 3) return std::accumulate(s.begin(), s.end(), 0);
    std::sort(s.begin(), s.end());
    int ans = INT_MAX;
    for(size_t i = 1; i < s.size() - 1; ++i)
    {
        unsigned k = 0;
        unsigned j = s.size() - 1;
        while(k < j) {
            if(k == i) ++k;
            if(j == i) --j;
            int sum = s[k] + s[i] + s[j];
            if(abs(sum - x) < abs(ans - x)) {
                ans = sum;
            }
            sum > x ? j-- : k++;
        }
    }
    return ans;
}

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
    int x;
    cin >> x;
    cout << getSum(s, x);
}
