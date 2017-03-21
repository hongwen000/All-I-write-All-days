template <bool b>
class Helper;

template <>
class Helper<true> {};

template <int a>
class LessThanZero {
    public:
    static constexpr int value = a < 0;
};

template <int a>
class A : Helper<LessThanZero<a>::value> {};

int main() {
    A<1> a;
    A<-1> b; // ok
}
