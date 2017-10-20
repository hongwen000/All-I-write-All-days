#include <type_traits>
#include <string>
#include <iostream>
using namespace std;
void logAndAddImpl(int idx, std::true_type)
{
    cout << "logAndAddImpl(int idx, std::true_type): " << idx << endl;
}
template<typename T>
void logAndAddImpl(T&& name, std::false_type)
{
    cout << "logAndAddImpl(T&& name, std::false_type): " << name << endl;
}
template<typename T>
void logAndAdd(T&& name)
{
    logAndAddImpl(
            std::forward<T>(name),
            std::is_integral<std::remove_reference_t<T>>()
            );
}
int main()
{
    logAndAdd("hhahah");
    logAndAdd(123);
}
