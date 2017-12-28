#include <map>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Data {
    string id;
    string date;
    string act;
    string amount;
    bool operator<(const Data& rhs) const {
        return id < rhs.id;
    }
};
int main() {
    map<string, int> total;
    string s;
    vector<Data> records;
    std::getline(cin, s);
    while(cin >> s) {
        vector<string> ss;
        int pos = 0;
        int next_pos = 0;
        for(int i = 0; i < 4; ++i) {
            next_pos = s.find(',', pos + 1);
            ss.push_back(s.substr(pos , next_pos - pos));
            pos = next_pos;
        }
        for(int i = 1; i < 4; ++i) {
            ss[i] = ss[i].substr(1);
        }
        Data d;
        d.id = ss[0];
        d.date = ss[1];
        d.act = ss[2];
        d.amount = ss[3];
        int money = atoi(ss[3].c_str());
        if(ss[2] == "withdraw")
            total[ss[0]] -= money;
        else 
            total[ss[0]] += money;
        records.push_back(d);
    }
    std::stable_sort(records.begin(), records.end());
    vector<Data>::iterator it1 = records.begin();
    vector<Data>::iterator it2 = records.begin();
    for(; it2 != records.end(); ++it2) {
        if(it1->id != it2->id) {
            cout << "Total:" << total[it1->id] << endl;
        }
        cout << it2->id <<"," << it2->date << "," << it2->act << "," << it2->amount << endl;
        it1 = it2;
    }
    cout << "Total:" << total[it1->id] << endl;
}
