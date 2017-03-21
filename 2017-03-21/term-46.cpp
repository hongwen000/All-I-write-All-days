#include <iostream>
using namespace std;
template<typename T> class Rational;
template<typename T>
const Rational<T> doMultiply(const Rational<T>& lhs, const Rational<T>& rhs) {
    return Rational<T>(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}
template<typename T>
class Rational {
    private:
        T numerat;
        T denominat;
    public:
        friend const Rational operator* (const Rational& lhs, const Rational& rhs)
        { return doMultiply(lhs, rhs); }
        Rational(const T& numerator = 0, const T& denominator = 1) : numerat(numerator), denominat(denominator) {};
        const T numerator() const {
            return numerat;
        }
        const T denominator() const {
            return denominat;
        }
};
template<typename T>
const Rational<T> operator* (const Rational<T>& lhs, const Rational<T>& rhs);
int main()
{
    Rational<int> obj1(4,3), obj2(2,1);
    cout << (obj1 * obj2).numerator() << "/" << (obj1 * obj2).denominator() << endl;
    cout << (obj1 * 2).numerator() << "/" << (obj1 * 2).denominator() << endl;
    return 0;
}


