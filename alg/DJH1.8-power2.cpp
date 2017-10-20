#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

inline
u_int64_t sqr(__int64_t a) {return a * a;}

u_int64_t power2(int n) {
    if(0 == n) return 1;
    return (n & 1) ? sqr(power2(n / 2)) * 2 : sqr(power2(n / 2));
}

int main() { 
    std::cout << power2(63);
    return 0; 
}
