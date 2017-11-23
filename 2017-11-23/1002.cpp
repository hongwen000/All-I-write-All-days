#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int main() {
    int m;
    cin >> m;
    vector<string> names, numbers;
    string name, number;
    string skip;
    string str;
    while(m--){
        cin >> str;
        int pos = str.find(',');
        name = str.substr(0, pos);
        number = str.substr(pos + 1);
        names.push_back(name);
        numbers.push_back(number);
    }
    int n;
    cin >> n;
    while(n--) {
        cin >> name;
        vector<string>::iterator it = std::find(names.begin(), names.end(), name);
        if(it == names.end()) {
            cout << name << ":No" << endl;
        } else {
            cout << name << ":" << numbers[std::distance(names.begin(), it)] << endl;
        }
    }
}

