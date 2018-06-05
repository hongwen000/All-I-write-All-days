#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <stack>
using namespace std;

int eval(const string &e, map<char, int> &f) {
    stringstream ss(e);
    char ch;
    stack<int> s;
    while(ss >> ch) {
        if(isalpha(ch)) {
            int val = f[ch];
            s.push(val);
        }
        else if(ch == '+') {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            s.push(val1 + val2);
        }
        else {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            s.push(val1 * val2);
        }
    }
    return s.top();
}

int main() {

}
