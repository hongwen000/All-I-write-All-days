#include <functional>
#include <iostream>

int main() {
    auto gcd = [&](int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    };
    std::cout << gcd(20, 30) << std::endl;
}
