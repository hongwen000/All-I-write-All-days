#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int tmp;
    std::vector<int> v1;
    std::vector<int> v2;
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        v1.push_back(tmp);
    }
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        v2.push_back(tmp);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int win = 0;
    int fail = 0;
    for(int i = 0; i < N; ++i)
        if(v1[i] > v2[i])
            win++;
        else if(v1[i] < v2[i])
            fail++;
        else
            continue;
    std::vector<int> dst;
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dst));
    int c = 0;
    for(int i = 0; i < N; ++i)
        if(find(dst.begin(), dst.begin() + N, * (v1.begin() + i)) != dst.begin() + N)
            ++c;
    cout << c << endl;
    if(c == N / 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

}
