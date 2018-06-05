#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int m;
    cin >> m;
    vector<pair<string, string> > records;
    string name, number;
    string skip;
    string str;
    while(m--){
        cin >> str;
        int pos = str.find(',');
        name = str.substr(0, pos);
        number = str.substr(pos + 1);
        records.push_back(std::make_pair(name, number));
    }
    std::sort(records.begin(), records.end());
    int n;
    cin >> n;
    while(n--) {
        cin >> name;
        vector<pair<string, string> >::iterator it = std::find_if(records.begin(), records.end(), [&](const pair<string, string>& p) {
                return (p.first == name);
                });
        if(it == records.end()) {
            cout << name << ":No" << endl;
        } else {
            cout << name << ":" << records[std::distance(records.begin(), it)].second << endl;
        }
    }
}
