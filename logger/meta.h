#include <string>
#include <functional>
#include <iostream>
#include <vector>
#include <type_traits>

using namespace std;

class base;

template <typename T>
struct sfinae_true : std::true_type {};

struct is_container_tester {
    template <typename T>
    static sfinae_true<typename std::iterator_traits<typename T::iterator>::iterator_category> test(int);

    template <typename>
    static std::false_type test(...);
};

template <typename T>
struct is_container : decltype(is_container_tester::test<T>(0)) {};

#define DECLARE(T, Name)                                                                                                   \
    T m_##Name{};                                                                                                          \
    public:                                                                                                                \
    T& get_##Name() {                                                                                                      \
        return m_##Name;                                                                                                   \
    }                                                                                                                      \
    template<typename U>                                                                                                   \
    void set_##Name(U&& rhs) {                                                                                             \
        m_##Name = std::forward<U>(rhs);                                                                                   \
    }                                                                                                                      \
    void imp_print##Name(const string& obj) const{                                                                         \
        cout << class_name << "::" << #T << " " << #Name << " = "<< obj << endl;                                                  \
    }                                                                                                                      \
    template<typename U>                                                                                                   \
    enable_if_t<std::is_base_of<base, U>::value, void> imp_print##Name(U& obj) const{                                      \
        obj.print();                                                                                                       \
    }                                                                                                                      \
    template<typename U>                                                                                                   \
    enable_if_t<!std::is_base_of<base, U>::value && !is_container<U>::value, void> imp_print##Name(U& obj) const{          \
        cout << class_name << "::" << #T << " " << #Name << " = "<< obj << endl;                                                  \
    }                                                                                                                      \
    template<typename U>                                                                                                   \
    enable_if_t<is_container<U>::value && !std::is_same<U, std::string>::value, void> imp_print##Name(U& container) const{ \
        auto beg = std::begin(container);                                                                                  \
        for(auto it = beg; it != std::end(container); ++it){                                                               \
            cout << "[" << std::distance(beg, it) << "]" << endl;                                                          \
             imp_print##Name(*it);                                                                                         \
        }                                                                                                                  \
    }                                                                                                                      \
    void print_##Name() const{                                                                                             \
        imp_print##Name(m_##Name);                                                                                         \
    }                                                                                                                      \
    private:

#define WATCH(Class, Name)                                       \
    class_name = #Class;                                         \
    auto funcobj_##Name = std::bind(&Class::print_##Name, this); \
    vecfunc.push_back(funcobj_##Name);

class base {
    protected:
    string class_name;
    vector<function<void()> > vecfunc;
    public:
    void print() const;
};
