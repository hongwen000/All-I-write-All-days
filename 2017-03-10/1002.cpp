#include <string>
#include <iostream>
using namespace std;
using s_iter = string::iterator;
s_iter replaceSegment(string &dst, const s_iter sbeg, const s_iter send, char ch)
{
    int length = static_cast<int>(send - sbeg);
    cout << length << endl;
    if (length) {
        string replacer = ch + to_string(length + 1);
        cout << "replacer is " << replacer << endl;
        dst.replace(sbeg, send + 1, replacer);
        return sbeg + replacer.size();
    }
    else
        return send + 1;
}
int main()
{
    string input;
    while(cin >> input && input != "x") {
        s_iter i, sbeg, send; 
        i = sbeg = send = input.begin();
        for( ; i != input.end(); ++i) {
            if( i != input.end() && *i != *(i + 1)) {
            i = replaceSegment(input, sbeg, send, *i);
            send = sbeg = i;
            --i;
            }
            else 
                ++send;
        }
        cout << input << endl;
    }
    return 0;
}

 
