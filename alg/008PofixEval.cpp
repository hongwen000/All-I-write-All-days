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
