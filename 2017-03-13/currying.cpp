#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

template <class A, class B, class C>
std::function<std::function<C(B)>(A)> Currying(std::function<C(A, B)>);
template <class BinaryFunc>
auto Currying(BinaryFunc&& f)
{
    return [=](auto a) {
        return [ f = std::move(f), a ](auto&& b)
        {
            return f(a, std::forward<decltype(b)>(b));
        };
    };
}

//vector<int>::const_iterator FindEqualTo(const vector<int>& v, int num)
//{
//    auto i(v.begin());
//    for (; i != end(v); ++i) {
//        if (*i == num)
//            return i;
//    }
//    return i;
//}

std::vector<int>::const_iterator FindEqualTo(const std::vector<int>& v, int num)
{
    return std::find_if(begin(v), end(v), (Currying(std::equal_to<int>())(num)));
}
int main()
{
    std::vector<int> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << *FindEqualTo(a, 5) << std::endl;
    return 0;
}
