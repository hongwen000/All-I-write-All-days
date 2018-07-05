namespace old
{
    template<int  N>
    constexpr int fibonacci() {return fibonacci<N-1>() + fibonacci<N-2>(); }
    template<>
    constexpr int fibonacci<1>() { return 1; }
    template<>
    constexpr int fibonacci<0>() { return 0; }
}

namespace now
{
    template<int N>
        constexpr int fibonacci()
        {
            if constexpr (N >= 2)
                return fibonacci<N-1>() + fibonacci<N-2>();
            else
                return N;
        }
}

#include <type_traits>
#include <limits>
using namespace std;

template<typename T>
bool foo()
{
    if constexpr(is_integral_v<T>)
        return true;
    else 
        return false;
}

template <typename ... Args>
auto sum1(Args ... args)
{
    return (args + ... + 0);
}

template <typename ... Args>
auto sum2(Args ... args)
{
    return (args + ... );
}

#include <fmt/format.h>
using namespace fmt;
int main()
{
    fmt::print("fibonacci(7) {}\n", old::fibonacci<7>());
    fmt::print("fibonacci(7) {}\n", now::fibonacci<7>());
    print("foo<int>() {}\n", foo<int>());
    print("foo<double>() {}\n", foo<double>());
    print("sum1 {}\n", sum1(1, 2, 3, 4, 5, 6));
    print("sum2 {}\n", sum2(1, 2, 3, 4, 5, 6));
    return 0;
}
