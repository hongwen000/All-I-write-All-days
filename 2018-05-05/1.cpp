#include <iostream>

template<typename U, typename V>
struct HasElement {
    static const bool value = false;
};

class M {};

template<typename T>
struct HasElement<M,T> {
    static const bool value = not HasElement<T,T>::value;
};

int main() {
    std::cout << HasElement<M,M>::value << std::endl;
    return 0;
}
