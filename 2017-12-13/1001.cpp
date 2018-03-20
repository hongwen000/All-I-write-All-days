#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int num[N];
    bool flag[N];
    for (int i = 0; i < N; ++i) {
        cin >> num[i];
        flag[i] = true;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; j++) {
            if(num[j] > num[i]) flag[i] = false;
        }
        for (int j = i + 1; j < N; j++) {
            if(num[j] < num[i]) flag[i] = false;
        }
    }
    std::cout << std::count_if(flag, flag + N, [](auto f) {return f;}) << std::endl;
}
