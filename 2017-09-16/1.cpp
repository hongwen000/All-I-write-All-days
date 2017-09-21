#include <type_traits>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    auto f = []() {
        return 1;
    };
    f();
    vector<int> vec;
    int key;
    for(int i = 0; i < 5; ++i) {
        cin >> key;
        vec.push_back(key);
    }
    cin >> key;
    if(find(vec.begin(), vec.end(), key) == vec.end()) {
        cout << "-1" << endl;
    }
    else {
        for(int i = 0; i < 5; ++i) {
            if(vec[i] == key)
                cout << i << endl;
        }
    }
    return 0;
}
