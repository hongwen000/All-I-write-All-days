#include <iostream>

using namespace std;

template<typename T, size_t N>
/*constexpr*/ size_t arraySize(T (&)[N]) noexcept
{
    return N;
}
int main()
{
    int key[] = { 1, 3, 5, 7};
    cout << arraySize(key) << endl;
    return 0;
}

