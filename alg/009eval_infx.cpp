#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;

void doCalc(stack<double>& s, char op) {
    double val1 = s.top();
    s.pop();
    double val2 = s.top();
    s.pop();
    switch(op) {
        case '+' :
            s.push(val1 + val2);
            break;
        case '-' :
            s.push(val2 - val1);
            break;
        case '*' :
            s.push(val1 * val2);
            break;
        case '/' :
            s.push(val2 / val1);
            break;
        default:
            break;
    }
}

bool isNumber(const string& word) {
    string::const_iterator it = word.cbegin();
    for(; it != word.end(); ++it)
        if(!isdigit(*it) && !(*it == '.'))
            return false;
    return true;
}

bool isVariable(const string& word) {
    return (word.size() == 1 && isalpha(word[0]));
}

bool isOperator(const string& word) {
    return (word.size() == 1 && (
            word == "+" ||
            word == "-" ||
            word == "*" ||
            word == "/" ));
}

vector<string> tokenize(string& e) {
    string::iterator it = e.begin();
    bool last_is_num = false;
    vector<string> ret;
    string tmp;
    for(; it != e.end(); ++it) {
        if(isdigit(*it) || *it == '.') {
            last_is_num = true;
            tmp += *it;
        } else {
            if(last_is_num) {
                ret.push_back(tmp);
                tmp.clear();
            }
            last_is_num = false;
            if(isblank(*it))
                continue;
            ret.push_back(string(1, *it));
        }
    }
    if(last_is_num) ret.push_back(tmp);
    return ret;
}

double eval(string e, map<char, double> f) {
    stringstream ss;
    string ch;
    stack<double> s;
    vector<string> tokens = tokenize(e);
    vector<string>::iterator it = tokens.begin();
    for(;it != tokens.end(); ++it)
        ss << *it << " " ;
    while(ss >> ch) {
        if(isNumber(ch)) {
            double val = atof(ch.c_str());
            s.push(val);
        } else if(isVariable(ch)) {
            double val = f[ch[0]];
            s.push(val);
        }
        else if(isOperator(ch)) {
            doCalc(s, ch[0]);
        }
    }
    return s.top();
}

string infix2pofix(string& e){
    stack<string> s;
    string r;
    vector<string> tokens = tokenize(e);
    vector<string>::iterator it = tokens.begin();
    map<string, int> priority;
    priority["("] = -1;
    priority["+"] = 0;
    priority["-"] = 0;
    priority["*"] = 1;
    priority["/"] = 1;
    for(; it != tokens.end(); ++it) {
        string word = *it;
        if(isNumber(word) || isVariable(word))
            r.append(word + " ");
        else if(isOperator(word)) {
            if(word == "(")
                s.push(word);
            else if(word == ")") {
                while (s.top() != "(") {
                    r.append(s.top() + " ");
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority[word] <= priority[s.top()]) {
                    r.append(s.top() + " ");
                    s.pop();
                }
                s.push(word);
            }
        }
    }
    while(!s.empty()){
        r.append(s.top());
        s.pop();
    }
    return r;
}


double eval_infix(string exp, map<char, double> sub) {
    string s = infix2pofix(exp);
    return eval(s, sub);
}

int main() {
    string s;
    map<char, double> sub;
    sub['a'] = 10;
    while(getline(cin, s)) {
        cout << eval_infix(s, sub) << endl;
    }
}
