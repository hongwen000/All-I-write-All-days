#include <numeric>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
vector<string> split_string(const std::string& strg) {
    auto range_low = 0;
    auto range_high = string::npos;
    vector<string> vec;
    while(true) {
        range_high = strg.find(' ', range_low + 1);
        if(range_high == string::npos) {
            vec.push_back(strg.substr(range_low));
            break;
        }
        else
          vec.push_back(strg.substr(range_low, range_high - range_low));
        range_low = range_high;
    }
    return vec;
}

std::string core(const std::string& strg)
{
    auto vec = split_string(strg);
    if(vec.size() > 1)
        for(auto it = vec.begin() + 1; it != vec.end(); ++it) {
            *it = it->substr(1);
        }
    std::string ret;
    for(auto& s : vec) {
        std::reverse(s.begin(), s.end());
        ret += s;
        ret += " ";
    }
    ret = ret.substr(0, ret.size() - 1);
    return ret;
}

int main()
{
    string s;
    getline(cin, s);
    cout << core(s) << endl;
}

