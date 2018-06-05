#include <map>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int num;
    std::map<int, int> m;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        m[num]++;
    }
    std::for_each(m.begin(), m.end(), [N](auto i) {
            if(i.second > N / 2)
                cout << i.first;
            });
}
