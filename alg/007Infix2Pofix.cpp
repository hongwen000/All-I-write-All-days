#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

vector<string> tokenize(const string& e) {
    string::const_iterator it = e.cbegin();
    bool last_is_num = false;
    vector<string> ret;
    string tmp;
    for(; it != e.cend(); ++it) {
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
            word == "(" || 
            word == ")" || 
            word == "/" ));
}

string infix2pofix(const string& e){
    stack<string> s;
    string r;
    vector<string> tokens = tokenize(e);
    vector<string>::const_iterator it = tokens.begin();
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

