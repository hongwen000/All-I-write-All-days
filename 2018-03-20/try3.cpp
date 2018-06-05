#include <iostream>
#include <type_traits>
struct A{
    std::string serialize() {
        return "I am A";
    }
};

struct B{};

template<typename T, typename = void>
struct hasSerialize: std::false_type {};

template<typename T>
struct hasSerialize<T, std::void_t<decltype(std::declval<T>().serialize())>> : std::true_type {};

template<typename T>
struct hasSerialize<T, std::enable_if_t<std::is_integral_v<T>>> : std::true_type {};

int main() {
    std::cout << hasSerialize<A>::value << std::endl;
    std::cout << hasSerialize<B>::value << std::endl;
    std::cout << hasSerialize<int>::value << std::endl;
    return 0;
}
