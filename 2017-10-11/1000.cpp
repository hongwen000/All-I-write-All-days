#include <iostream>
#include <cctype>
#include <sstream>
#include <vector>
using namespace std;
string op = "+-*/()#";
bool isOP(char a) {
    return op.find(a) != string::npos;
}
vector<string> tokenize(const string str) {
    int pos = 0, count = 0;
    vector<string> tokens;
    while(!isOP(str[pos]))
        ++pos;
    tokens.push_back(str.substr(0, pos));
    for(size_t i = pos; i < str.size(); ++i) {
        count++;
        if(isOP(str[i])) {
            tokens.push_back(str.substr(pos + 1, count - 1));
            tokens.push_back(str.substr(i, 1));
            pos = i;
            count = 0;
        }
    }
    if((size_t)pos != str.size() - 1) {
           tokens.push_back(str.substr(pos + 1));
    }
    auto it = tokens.begin();
    while(it != tokens.end()) {
        if(it->empty())
            it = tokens.erase(it);
        else
            ++it;
    }
    return tokens;
}
vector<string> tokenize2(string str) {
    auto it = str.begin();
    while(it != str.end()) {
        if(isOP(*it)) {
            it++ = str.insert(it, ' ');
            it++ = str.insert(it + 1, ' ');
        } else
            ++it;
    }
    stringstream ss(str);
    vector<string> tokens;
    while(ss >> str)
        tokens.push_back(str);
    return tokens;
}
int main() {
    std::string s,str;
    std::getline(std::cin ,s);
    for(auto it = s.begin(); it != s.end(); ++it) {
        if(!std::isblank(*it)){
            str.push_back(*it);
        }
    }
    auto tokens = tokenize2(str);
    for(auto i : tokens)
        cout << i << endl;
}

