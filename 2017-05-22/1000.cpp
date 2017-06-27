#include <fstream>
#include <iostream>
#include <sstream>
#include <type_traits>
#include <vector>

using namespace std;

template <int a, typename = void>
class T;

template <int a>
class T<a, enable_if_t<a == 0>> {
public:
    static constexpr int value = 0;
};

template<class T, class Enable = void>
class A ; 

template<class T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
    public:
    static constexpr int value = 0;
};

template<int T, typename Enable = void>
class vA ; 


template <bool b>
class Helper;

template <>
class Helper<true> {
    public:
    typedef bool type;
};

template <int a>
class isZero {
    public:
    static constexpr int value = (a == 0);
};

//template<int T>
//class vA<T, Helper<isZero<T>::value>::type> {
//    public:
//    static constexpr int value = 0;
//}; 
int main()
{

    //cout << T<0>::value << endl;
    cout << A<double>::value << endl;
    cout << T<0>::value << endl;
    //cout << vA<0>::value << endl;
    Helper<isZero<0>::value>::type hhh = false;
    enable_if<true, int>::type a;
    enable_if<true>::type b;
    return 0;
}
