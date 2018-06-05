#include <iostream>
#include <string>
struct A{
    std::string serialize() {
        return "I am A";
    }
};

struct B{};
template<typename T>
struct hasSerialize
{
    private:
        template<typename U>
            constexpr static auto check(int) -> decltype(std::declval<U>().serialize(), std::true_type());
        template<typename U>
            constexpr static std::false_type check(...);
    public:
        static constexpr bool value = std::is_same_v<decltype(check<T>(0)), std::true_type>;
};

template <class T> auto serialize(T& obj) -> typename std::enable_if<hasSerialize<decltype(obj)>::value, std::string>::type
{
    return obj.serialize();
}

int main() {
    std::cout << hasSerialize<A>::value << std::endl;
    std::cout << hasSerialize<B>::value << std::endl;
    return 0;
}
