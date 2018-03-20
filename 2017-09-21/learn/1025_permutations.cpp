#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > permutations(int n) {
    std::vector<int> next;
    for (int i = 1; i < n + 1; ++i) {
        next.push_back(i);
    }
    std::vector<std::vector<int> > ret;
    ret.push_back(next);
    while(true) {
        std::pair<int, int> last_plus_interval(n - 1, n);
        for (int i = 0; i < n; ++i) {
            if(i == n - 1 && last_plus_interval.first == n - 1) {
                next.clear();
                for (int i = n; i > 0; --i) {
                    next.push_back(i);
                    ret.push_back(next);
                    break;
                }
            }
            else{
                if(next[i] < nex[i + 1])

            }
        }
    }
}
