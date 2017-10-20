#include <iostream>
using namespace std;
int countOnes(unsigned int n) {
    int ones = 0;
    while(0 < n) {
        ones += (1 & n);
        n >>= 1;
    }
    return ones;
}

int main() {
    unsigned int a = 235443213;
    std::cout << countOnes(a) << std::endl;
    std::cout << __builtin_popcount(a) <<endl;
}
