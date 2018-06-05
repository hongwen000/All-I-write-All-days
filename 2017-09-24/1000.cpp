#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <iostream>
using namespace std;

double sin(double x, int N) {
    int sig = N % 2 == 1 ? 1 : -1;
    int coeffcient = 2 * N - 1;
    double term = 1;
    for(int i = 1; i <= coeffcient; ++i)
        term *= (x / i);
    term *= sig;
    if(N > 1)
        return sin(x, N -1) + term;
    else
        return term;
}

int calc(int n) {
    if (n == 1 || n == 2)
        return n;
    else
        return calc(n - 1) + calc(n - 2);
}

char a[] = "1234";

std::deque<char> que;
std::queue<char> ret;

void perm(std::deque<char> que, int n, std::queue<char> ret){
    if(n == 4) {
        while(!ret.empty()) {
            cout << ret.front();
            ret.pop();
        }
        while(!que.empty()) {
            cout << que.front();
            que.pop_front();
        }
        cout << endl;
       // while(!ret.empty()) {
       //     cout << ret.front();
       //     ret.pop();
       // }
       // while(!que.empty()) {
       //     cout << que.back();
       //     que.pop_back();
       // }
       // cout << endl;
        return;
    }
    else {
        auto que2 = que;
        que2.push_back(a[n]);
        perm(que2, n + 1, ret);
        //auto que3 = que;
        //que3.push_front(a[n]);
        //perm(que3, n + 1, ret);
        if(!que.empty()) {
            std::queue<char> ret1 = ret;
            ret1.push(que.front());
            auto que3 = que;
            que3.pop_front();
           // std::queue<char> ret2 = ret;
           // ret2.push(que.back());
           // auto que4 = que;
           // que4.pop_back();
            perm(que3, n, ret1);
           // perm(que4, n, ret2);
        }
    }
}
int main()
{
    double a = sin(1, 3);
    cout << a << endl;
    printf("%f\n", a);
}
