#include <cstring>
template<typename T>
bool cmp(const T& lhs, const T& rhs)
{
    return lhs == rhs;
}

template<typename T>
bool cmp(T* lhs, T* rhs)
{
    return (*lhs) == (*rhs);
}

bool cmp(char* lhs, char* rhs)
{
    return strcmp(lhs, rhs) == 0;
}
