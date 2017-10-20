#include <list>
#include <iostream>
#include <type_traits>
#include <iterator>
struct a{
    using value_type = int;
    value_type a = 10;
};
#include <algorithm>
using namespace std;
template <typename ForwardIterator>
ForwardIterator find_median(ForwardIterator first1, ForwardIterator last1, ForwardIterator first2, ForwardIterator last2 )
{
    static list<typename iterator_traits<ForwardIterator>::value_type> lst;
    std::merge(first1, last1, first2, last2, std::back_inserter(lst));
    return lst.begin();
}
int main() {
    list<int> lst1 {1,3,7};
    list<int> lst2 {4,2,5};
    auto ret = find_median(lst1.begin(), lst1.end(), lst2.begin(), lst2.end());
    cout << *ret;
}
