#include <iostream>
using namespace std;
u_int64_t fib(int n, u_int64_t& pre) {
    if(0 == n) {
        pre = 1; return 0;
    }
    else {
        u_int64_t prePre;
        pre = fib(n - 1, prePre);
        return pre + prePre;
    }
}

u_int64_t fibI(int n) {
    u_int64_t f = 1, g = 0;
    while(n--) {g += f; f = g - f;}
    return g;
}

int main() {
    std::cout << fibI(10);
}
