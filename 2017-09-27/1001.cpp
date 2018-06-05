#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    std::vector<int> vec, max_left(n), max_right(n);
    int tmp;
    while(n--) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    for(int i = 0; i < vec.size(); ++i) {
        int max = 0;
        for(int j = 0; j < i; ++j){
            auto high = vec[j];
            auto tmp = high - vec[i];
            if(tmp > max)
                max = tmp;
        }
        max_left[i] = max;
    }
    for(int i = 0; i < vec.size(); ++i) {
        int max = 0;
        for(int j = i + 1; j < vec.size(); ++j){
            auto high = vec[j];
            auto tmp = high - vec[i];
            if(tmp > max)
                max = tmp;
        }
        max_right[i] = max;
    }
    int sum = 0;
    for(int i = 0; i < vec.size(); ++i) {
        sum += max_left[i] < max_right[i] ? max_left[i] : max_right[i];
    }
    cout << sum << endl;
}
//
