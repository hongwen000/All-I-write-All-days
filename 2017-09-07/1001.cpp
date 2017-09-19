#include <numeric>
#include <vector>
#include <iostream>
using namespace std;
int sum(vector<int> v) {
    return std::accumulate(v.begin(), v.end(), 0);
}
int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(v) << endl;
}
