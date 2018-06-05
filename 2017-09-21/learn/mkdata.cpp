#include <set>
#include <utility>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
constexpr int MAX_ELEMENT = 50;
constexpr int MAX_CASES = 100;
int main()
{
    srand(time(NULL));
    int cases = 100;
    cin >> cases;
    while(cases --) {
    int N = rand() % MAX_ELEMENT;
    cout << N << endl;
    std::vector<int> eles;
    for(int i = 0; i < N; ++i) {
        int ele = rand() % (MAX_ELEMENT * 2);
        eles.push_back(ele);
        cout << ele << endl;
    }
    int P;
    if(N == 0) {
        P = 0;
        cout << P << endl;
    }
    else {
        P = rand() % (N * N);
    }
    cout << P << endl;
    std::set<std::pair<int, int>> relations;
    for(int i = 0; i < P;) {
        int xi = rand() % N;
        int yi = rand() % N;
        std::pair<int, int> rel(eles[xi], eles[yi]);
            relations.insert(rel);
            cout << rel.first << ' ' << rel.second << endl;
            ++i;
    }
    }
}
