#include  <algorithm>
using namespace std;
template <typename T>
auto find_lower_bound(T seq[], int n, const T& value) -> decltype(lower_bound(std::forward<T*>(seq), std::forward<T*>(seq+n-1),std::forward(value)))
{
    return lower_bound(std::forward<T*>(seq), std::forward<T*>(seq+n-1),std::forward(value));
}
