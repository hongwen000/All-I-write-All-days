#include <string>
#include <iostream>
using namespace std;
using s_iter = string::iterator;
inline
bool is_dec(const char& ch) 
    { return (ch - 48) >= 0 && (ch - 48) <= 9; } 
s_iter replaceSegment(string &dst, const s_iter sbeg, const s_iter send, const char ch)
{
    int replacer_length = atoi(string(sbeg, send).substr(1).c_str());
    int desting = sbeg - dst.begin();
    if (replacer_length) {
        string replacer = string(replacer_length, ch);
        dst.replace(sbeg, send, replacer);
        return dst.begin() + desting + replacer.size();
    }
    else{
        dst.erase(sbeg+1);
        dst.erase(sbeg);
        return send - 2;
    }
}
int main()
{
    string input;
    while(cin >> input && input != "x") {
        s_iter i, sbeg, send; 
        i = sbeg = input.begin();
        send = sbeg + 1;
        for( ; i != input.end(); ++i) {
            if( i != input.end() && is_dec(*i) && !(is_dec(*(i+1)))) {
             i = replaceSegment(input, sbeg, send, *sbeg);
             sbeg = i;
             send = sbeg + 1;
             --i;
            }
            else if(i != input.end() && !is_dec(*i) && !(is_dec(*(i+1)))){
                ++send;
                ++sbeg;
            }
            else
                ++send;
        }
        cout << input << endl;
    }
    return 0;
}

 
