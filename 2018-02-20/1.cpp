#include <iostream>
template <typename T, typename Inc>
struct A{
    A(T _now):now(_now){}
    T& operator++(){
        Inc inc_;
        now = inc_(now);
        return *this;
    }
    T& operator*() const{
        return now;
    }
private:
    T now;
};

template <typename T, typename Func> 
T incc(const T& now, Func func)
{
    return func(now);
}

int main()
{
    auto myinc = [](auto i){return i*2;};
    A<int,decltype(myinc)> a(1);
    std::cout << ++a << std::endl;
    std::cout << incc(1,myinc) << std::endl;
}
