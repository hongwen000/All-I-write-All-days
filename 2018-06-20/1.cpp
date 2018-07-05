#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;
char *mystrncpy(char* _dst, const char* _src, size_t count)
{
    auto len = strlen(_src);
    if(count < len)
    {
        len = count;
    }
    memcpy(reinterpret_cast<void*>(_dst), reinterpret_cast<const void *>(_src), len);
    for(size_t i = len; i < count; ++i)
        _dst[i] = 0;
    return _dst;
}
int main()
{
    char dst [] = "abcggg";
    char src [] = "123";
    mystrncpy(dst, src, 5);
    cout << dst << endl;    
    assert(strlen(dst) == 3);
    return 0;
}
