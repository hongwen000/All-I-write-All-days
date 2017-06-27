#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;
int main()
{
    vector<pair<string,int>> v;
    v.push_back(make_pair<string,int>("A",8));
    v.push_back(make_pair<string,int>("B",7));
    v.push_back(make_pair<string,int>("C",6));
    sort(v.begin(), v.end(), [](auto &l, auto &r) {
            return l.second < r.second;
            });
    for(auto i : v)
        cout << i.first << " : " << i.second << endl;
    return 0;
}

    
