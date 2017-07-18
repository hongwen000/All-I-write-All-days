//clang++ undefined reference to `std::__once_callable, g++ OK
#include <mutex>
#include <iostream>
#include <thread>
#include <string>
#include <future>
using namespace std;
struct X
{
    void foo(int i, const string& s) {
        cout << "foo " << i << " " << s << endl;
    }
    string bar(const string& s) {
        cout << "bar " << s << endl;
        return s;
    }
};
X x;
auto f1 = async(&X::foo, &x, 42, "hello");
auto f2 = async(&X::bar, x, "goodbye");
struct Y
{
    double operator()(double f) {
        return f;
    }
};
Y y;
auto f3 = async(Y{}, 3.141);
auto f4 = async(ref(y), 2.718);
X baz(X&) {
    cout << "baz" << endl;
    return X{};
}
auto f0 = async(baz, ref(x));
class move_only
{
public:
    move_only(){
        cout << "move_only default ctor" << endl;
    }
    move_only(move_only&&){
        cout << "move cotr" << endl;
    }
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&){return *this;}
    move_only& operator=(const move_only&) = delete;
    void operator() (){}
};
auto f5 = async(move_only{});
int main()
{

}
