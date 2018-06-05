#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int sum[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++) {
            sum[i][j] = INT_MIN;
        }
    }
    int num[N];
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
        sum[i][i] = num[i];
    }
    for (int i = 0; i < N; ++i) {
        for(int j = i; j < N; ++j) {
            if(i == j) {
                continue;
            } else {
                sum[i][j] = sum[i][j - 1] + sum[j][j];
            }
        }
    }
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; j++) {
//            if(i > j) cout << "/\t";
//            else cout << sum[i][j] <<"\t";
//        }
//        cout << endl;
//    }
    int* p1 = (int*)sum;
    int* p2 = p1 + N * N;
    std::cout << *std::max_element(p1, p2) << std::endl;
}
