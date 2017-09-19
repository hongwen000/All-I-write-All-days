#include <algorithm>
#include <list>
#include <iostream>
#include <cstddef>
using namespace std;
template <typename T>
size_t ListLength(const list<T>& L) {
    size_t length = 0;
    typename list<T>::const_iterator it = L.begin();
    for(; it != L.end(); ++it) {
        ++length;
    }
    return length;
}

template <typename T>
void ListUnique(list<T>& L) {
    list<T> result;
    for(typename list<T>::iterator it = L.begin(); it != L.end(); ++it)
        if(std::find(result.begin(), result.end(),*it) == result.end())
            result.insert(result.end(), *it);
    L = result;
}
template <typename T>
list<T> reverseMerge(const list<T>& L1, const list<T>& L2) {
    typedef typename list<T>::const_iterator c_iter;
    c_iter it1 = L1.begin();
    c_iter it2 = L2.begin();
    list<T> result;
    while(it1 != L1.end() || it2 != L2.end()) {
        if(it1 == L1.end()) {
            result.insert(result.begin(), *it2);
            ++it2;
        }
        else if(it2 == L2.end()) {
            result.insert(result.begin(), *it1);
            ++it1;
        }
        else {
            if(*it1 > *it2) {
                result.insert(result.begin(), *it2);
                ++it2;
            }
            else {
                result.insert(result.begin(), *it1);
                ++it1;
            }
        }
    }
    return result;
}
int main()
{
    list<int> a {1, 2, 2, 4, 4};
    list<int> b {0, 3, 5, 6};
    a = reverseMerge(a, b);
    for(auto i : a)
        cout << i << endl;

}
