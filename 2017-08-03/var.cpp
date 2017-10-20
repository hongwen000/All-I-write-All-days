#include <any>
#include <iostream>
#include <vector>
using namespace std;
struct S {
    S(vector<int> _v, int _offset): v(_v), offset(_offset) {}
    vector<int> v;
    int offset;

};
template <typename T>
void circleTranslation(T x, T y, const initializer_list<any>&& lst)
{
    for(int j = 0; j < lst.size(); j += 2) {
        for(auto i : any_cast<vector<int>>(*(lst.begin() + j))) {
            i = i - any_cast<int>(*(lst.begin() + j + 1));
            cout << i << endl;
        }
    }
}

int main()
{
    vector<int> v1 {1, 1, 1};
    vector<int> v2 {5, 5, 5};
//    circleTranslation(1, 1, {v1, 1});
    circleTranslation(1, 1, {v1, 1, v2, 1, v1, 1});
}
