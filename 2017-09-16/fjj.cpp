#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void insertReserveOrder(vector<T>& L, T x) {
    int i = 0;
    for(; i < L.size(); ++i)
        if(x< L[i])
            break;
    L.insert(L.begin() + i, x);
}
template <typename T>
void deleteRange(vector<T>& L, T x, T y) {
    for(auto it = L.begin(); it != L.end();)
        if(*it >= x && *it <= y)
            it = L.erase(it);
        else
            ++it;
}
int main()
{
    vector<int> a{0, 1, 2, 5};
    deleteRange(a, 1, 2);
    for(auto i : a)
        cout << i << endl;
}
