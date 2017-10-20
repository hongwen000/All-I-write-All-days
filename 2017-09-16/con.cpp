#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
#include <list>
using namespace std;
namespace detail_ {
 
template < typename ForwardIterator >
ForwardIterator advance(ForwardIterator it, int n, std::forward_iterator_tag)
{
    while (n--) ++it;
    return it;
}
 
template < typename RandomAccessIterator >
RandomAccessIterator advance(RandomAccessIterator it, int n, std::random_access_iterator_tag)
{
    it += n;
    return it;
}
 
template < typename Iterator >
Iterator advance(Iterator it, int n)
{
    using tag = typename std::iterator_traits<Iterator>::iterator_category;
    // We're doing this silly and not allowing input iterators, we should make a readable message
    static_assert(std::is_base_of<std::input_iterator_tag, tag>::value, "Can only advance ForwardIterators and their refinements.");
 
    return detail_::advance(it, n, tag{});
}

}
 
int main() {
    vector<int> vec {1, 2, 4};
    auto it = find(vec.begin(), vec.end(), 2);
    auto it2 = detail_::advance(it, 1);
    cout << *it2 << endl;
}
