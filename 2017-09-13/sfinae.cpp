#include <string>
#include <iostream>
#include <type_traits>
using namespace std;
class Person {
public:
    template <typename T,
       typename = std::enable_if_t<!std::is_same<Person, std::decay_t<T>>::value>>
    explicit Person(T&& n)
        : name(std::forward<T>(n))
    {
        static_assert(std::is_constructible<std::string, T>::value, "Parameter n can't be used to construct a std::string"
                );
        cout << "universial ref ctor is called, name is " << name << endl;
    }
    Person(const Person& rhs) : name(rhs.name) {
        cout << "copy ctor is called, name is " << name << endl;
    }
private:
    std::string name;
};

int main()
{
    Person a(string("zhiru"));
    Person b(a);
    Person c(u"darui");
}

