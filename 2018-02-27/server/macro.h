#ifndef H_MY_MACROS_H
#define H_MY_MACROS_H
#include <vector>
#include <string>
#define MYDEFINE(CLASS,TYPE,NAME)                                 \
    struct _##CLASS_##TYPE_##NAME {                             \
        _##CLASS_##TYPE_##NAME() :                              \
        w(#CLASS, #TYPE, #NAME){}                               \
        _##CLASS_##TYPE_##NAME& operator=(const TYPE& rhs) {    \
            m_##NAME = rhs;                                     \
            w.update(m_##NAME);                                 \
            return *this;                                       \
        }                                                       \
        TYPE& operator*() {                                     \
            return m_##NAME;                                    \
        }                                                       \
        TYPE* operator->() {                                    \
            return & this->operator*();                         \
        }                                                       \
        void update() {                                         \
            w.update(m_##NAME);                                 \
        }                                                       \
        private:                                                \
            TYPE m_##NAME;                                      \
            Watcher<TYPE> w;                                    \
    } NAME;                                                     \

struct is_WatcherObject_tag{};

struct AbstractWatcherObject {
    using values_type = std::vector<std::string>;
    virtual values_type watcher_property_value() const = 0;
    using info_type = std::vector<std::pair<std::string, std::string>> ;
};

struct WatcherObject {
    using values_type = std::vector<std::string>;
    using info_type = std::vector<std::pair<std::string, std::string>> ;
    using is_WatcherObject = is_WatcherObject_tag;
};

#define MYDECLARE(CLASS,TYPE,NAME)                                 \
    struct _##CLASS_##TYPE_##NAME {                             \
        _##CLASS_##TYPE_##NAME() :                              \
        w(#CLASS, #TYPE, #NAME){}                               \
        _##CLASS_##TYPE_##NAME& operator=(const TYPE& rhs) {    \
            m_##NAME = rhs;                                     \
            w.update(m_##NAME);                                 \
            return *this;                                       \
        }                                                       \
        const TYPE& operator*() {                               \
            return m_##NAME;                                    \
        }                                                       \
        private:                                                \
            TYPE m_##NAME;                                      \
            Watcher<TYPE> w;                                    \
    };                                                     

template<typename T>
struct _TYPE_TO_NAME{
};

#define MY_REGISTER_WATCHER_TYPE(CLASS)                                 \
    class CLASS;                                                        \
    template<>                                                          \
    struct _TYPE_TO_NAME<CLASS> {                                       \
        static constexpr const char* name = #CLASS;                     \
    };                                                                  \
    class CLASS : public AbstractWatcherObject

#define MY_REGISTER_WATCHER_INFO(CLASS)                                 \
    auto ref = getRegisteredClassInfo();                                \
    (*ref)[#CLASS] =

#endif
