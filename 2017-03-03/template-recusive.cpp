#include <iostream>

template<typename T>
struct InfRec {
        static const int value = InfRec< InfRec<T> >::value;
};

int main() {
        std::cout << InfRec<int>::value << std::endl;
            return 0;
}
