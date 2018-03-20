#include <list>
#include <iostream>
#include <type_traits>
#include <iterator>
#include <algorithm>
using namespace std;
template <typename ForwardIterator>
ForwardIterator find_median(ForwardIterator first1, ForwardIterator last1, ForwardIterator first2, ForwardIterator last2 )
{
    static std::list<typename std::iterator_traits<ForwardIterator>::value_type> ret;
    ret.clear();
    std::merge(first1, last1, first2, last2, std::back_inserter(ret));
    if(ret.size() % 2 == 0) {
        for(auto it = ret.begin(); it != ret.end(); ++it) {
            if(std::distance(ret.begin(), it) == (ret.size() / 2 - 1)) {
                auto i1 = *it;
                auto i2 = *(++it);
                auto med = (i1 + i2) / 2.0;
                ret.push_front(med);
            }
        }
    } else {
        for(auto it = ret.begin(); it != ret.end(); ++it) {
            if(std::distance(ret.begin(), it) == ret.size() / 2) {
                auto i1 = *it;
                ret.push_front(i1);
            }
        }
    }
    return ret.begin();
}
int main() {
    list<double> lst1 {2,1,1};
    list<double> lst2 {1,1,2};
    auto ret = find_median(lst1.begin(), lst1.end(), lst2.begin(), lst2.end());
    cout << *ret;
}
