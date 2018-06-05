#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <cstdlib>
using namespace std;
int main() {
    int V[5][5];
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            V[i][j] = i * 5 + j;
            cout << V[i][j] << ' ';
        }
        cout << endl;
    }
    int P[5][5];
    std::copy(std::begin(V[0]), std::end(V[4]), std::begin(P[0]));
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cout << P[i][j] << ' ';
        }
        cout << endl;
    }
}
