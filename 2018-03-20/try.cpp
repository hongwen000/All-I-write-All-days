#include <iostream>
template<typename T>
bool f(const T&){
    return true;
}

auto lambda = [](auto&& x) -> decltype(x.method()) {};

auto a = f(lambda);

int main()
{
    std::cout << a << std::endl;
}
