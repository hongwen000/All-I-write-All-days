#include <functional>
#include <iostream>
#include <string>
using namespace std;

template <template <typename> class F>
class Functor {
    public:
    template <typename A>
    static F<A> Unit(const A& a)
    {
        return F<A>(a);
    }
    template <typename A, typename B>
    static F<B> Fmap(const F<A>& fa, function<B(A)> f)
    {
        return F<B>(f(fa.getPrimite()));
    }
};

int f(int x) {
    return x * x;
};

template <typename T>
class egg {
public:
    explicit egg(const T _primite)
        : primite(_primite)
    {
        str = to_string(primite) + string("个大鸭蛋");
    }
    const char& at(size_t _pos) const
    {
        return str.at(_pos);
    }
    const int getPrimite() const
    {
        return primite;
    }
    const string getContent() const
    {
        return str;
    }

private:
    T primite;
    string str;
};

template <class T>
ostream& operator<<(ostream& os, const egg<T>& _egg)
{
    os << _egg.getContent();
    return os;
}

int main()
{
    int a(2), b(4);
    const egg<int> fa = Functor<egg>::Unit<int>(a);
    const egg<int> fb = Functor<egg>::Fmap<int, int>(fa, f);
    cout << fa << endl;
    cout << fb << endl;
    return 0;
}
