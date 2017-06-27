#pragma once
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>

namespace JJ {
template <class T>
inline T* _allocate(ptrdiff_t size, T*)
{
    std::set_new_handler(nullptr);
    T* tmp = (T*)(::operator new((size_t)(size * sizeof(T))));
    if (!tmp) {
        std::cerr << "out of memory" << std::endl;
        exit(1);
    }
    return tmp;
}

template <class T>
inline void _deallocate(T* buffer)
{
    ::operator delete(buffer);
}

template <class T1, class T2>
inline void _construct(T1* p, const T2& value)
{
    new (p) T1(value);
}

template <class T>
inline void _destory(T* ptr)
{
    ptr->~T();
}

template <class T>
class allocator {
public:
    using value_type        = T;
    using pointer           = T*;
    using const_pointer     = const T*;
    using reference         = T&;
    using const_reference   = const T&;
    using difference_type   = ptrdiff_t;
    using size_type         = size_t;

    template <class U>
    struct rebind {
        using other = allocator<U>;
    };
    
    pointer allocate(size_type n, const void* hint = 0) {
        return _allocate((difference_type) n, (pointer) nullptr);
    }

    void deallocate(pointer p, size_type n) {
        _deallocate(p);
    }

    void construct(pointer p, const T& value) {
        _construct(p, value);
    }

    void destroy(pointer p) {
        _destory(p);
    }

    pointer address(reference x) {
        return (pointer)&x;
    }

    const_pointer const_address(const_reference x) {
        return (const_pointer)&x;
    }

    size_type max_size() const {
        return size_type(UINT_MAX/sizeof(T));
    }
};
}






