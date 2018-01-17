#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int getNumOfDigit(int m)
{
    if(!m) return 1;
    int ret = 1;
    while(m /= 10) ret++;
    return ret;
}
int getDigit(int m, int n){
    return (int)(m / pow(10, n)) % 10;
}
void baseSort(vector<int> s)
{
    int m = *std::max_element(s.begin(), s.end());
    for(int n = 0; n < getNumOfDigit(m); ++n) {
        std::stable_sort(s.begin(), s.end(), [n](auto i, auto j){return getDigit(i, n) < getDigit(j, n);}); 
        std::for_each(s.begin(), s.end(), [](auto i){cout << i << ", ";});
        cout << endl;
    }
}

int main()
{
    baseSort(vector<int>{314, 617, 253, 335, 19, 237, 464, 121, 46, 231, 176, 344});
}
