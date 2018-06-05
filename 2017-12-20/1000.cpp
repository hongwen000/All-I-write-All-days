#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
void update(vector<int>& idx, int &start, int &len)
{
    int s = 0, sv = idx[0], l = 0, lv = idx[0];
    for(size_t i = 1; i < idx.size(); ++i) {
        if(idx[i] == -1) return;
        if(idx[i] < sv){
            sv = idx[i];
            s = i;
        }
        if(idx[i] > lv){
            lv = idx[i];
            l = i;
        }
    }
    len = lv - sv + 1;
    start = sv;
}
int main()
{
    string S, T;
    cin >> S >> T;
    auto s_char = std::set<char> {S.begin(), S.end()};
    auto t_char = std::set<char> {T.begin(), T.end()};
    if(!includes(s_char.begin(), s_char.end(), t_char.begin(), t_char.end())){
        cout << "No" << endl;
        return 0;
    }
    vector<int> idx(T.size(), -1);
    int start = 0;
    int len = S.size();
    for(size_t i = 0; i < S.size(); ++i) {
        size_t r = 0;
        if((r = T.find(S[i])) != string::npos) {
            idx[r] = i;
        }
        int _start = start;
        int _len = len;
        update(idx, _start, _len);
        if(_len < len) {
            len = _len;
            start = _start;
        }
    }
    cout << S.substr(start, len);
}
