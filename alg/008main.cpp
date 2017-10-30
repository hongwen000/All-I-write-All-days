#include <string>
#include <iostream>
#include <map>
using namespace std;
extern double eval(string e, map<char, double> f);

int main() {
    map<char, double> sub;
    sub['x'] = 1.25;
    string s;
    while(getline(cin, s)) {
        cout << eval(s, sub) << endl;
    }
    return 0;
}
