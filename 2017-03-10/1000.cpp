#include <iostream>
template<typename T>
auto doubleCapacity(const T *arr, size_t size)
{
    auto doubled_array = new T[size * 2];
    for(size_t i = 0; i < size * 2; ++i)
        doubled_array[i] = i < size ? arr[i] : 0;
    return doubled_array;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    auto b = doubleCapacity(a, 5);
    for(int i=0;i < 2*5;i++)
        std::cout << *(b + i) << " ";
    return 0;
}
