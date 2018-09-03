#include <string>
#include <stack>
using namespace std;
bool match(char t, char c)
{
    if(t == '(' && c == ')') return true;
    if(t == '[' && c == ']') return true;
    if(t == '{' && c == '}') return true;
    return false;
}

bool isValid(string s) {
    stack<char> st;
    for(auto c : s)
    {
        if(st.empty())
            st.push(c);
        else
        {
            auto t = st.top();
            if(match(t, c))
                st.pop();
        }
    }
    return st.empty();
}
