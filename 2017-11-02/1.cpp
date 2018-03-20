#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void func(T a) {
    T b;
    b = false;
}
int main()
{
    vector<bool> v;
    v.push_back(false);
    func(v[0]);
}
