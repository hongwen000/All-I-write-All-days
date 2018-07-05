#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include <type_traits>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        if(s.size() == 1) return s;
        vector<int> st(s.size());
        vector<int> len(s.size());
        st[0] = 0;
        len[0] = 1;
        if(s[0] == s[1])
        {
            st[1] = 0;
            len[1] = 2;
        }
        else
        {
            st[1] = 1;
            len[1] = 1;
        }
        int m = len[1] > len[0];
        int cont = s[0] == s[1];
        for(int i = 2; i < s.size(); ++i)
        {
            cont = cont && s[i] == s[i-1];
            cout << "i = " << i << ", st[i-1] = " << st[i-1] << ", len[i-1] = " << len[i-1] << endl;
            int front = i - len[i-1] - 1 + cont;
            cout << "front = " << front << endl;
            if(front < 0) 
            {
                st[i] = i;
                len[i] = 1;
                cont = false;
            }
            else if(s[front] == s[i])
            {
                cout << front << " == " << i << endl;
                st[i] = front;
                len[i] = len[i-1] + 2 - cont;
                cout << "len[m] = " << len[m] << ", len[i] = " << len[i] << endl;
                if(len[i] > len[m]) m = i;
                else if (len[i] == len[m] && st[m] + len[m] == st[i])
                {
                    bool same = true;
                    cout << "SPECIAL CASE" << endl;
                    cout << "Len[i] = " << len[i] << " len[m] = " << len[m] << " st[m] = " << st[m] << " len[m] = " \
                            << len[m] << " st[i] = "<< st[i] << endl;
                    int it = 0;
                    while(it < len[m])
                    {
                        if(s[st[i] + it] != s[st[m] +it])
                        {
                            cout << "Not same, it = " << it << endl;
                            same = false;
                            break;
                        }
                        ++it;
                    }
                    if(same) len[m] = 2 * len[m];
                }
            }
            else
            {
                st[i] = i;
                len[i] = 1;
                cont = false;
            }
            
            if(len[i] == 1 && s[i-1] == s[i])
            {
                st[i] = i - 1;
                len[i] = 2;
                if(len[i] > len[m]) m = i;
                cont = true;
            }
            else if(i > 1 && len[i] == 1 && s[i-2] == s[i])
            {
                st[i] = i - 2;
                len[i] = 3;
                if(len[i] > len[m]) m = i;
                cont = false;
            }
        }
        cout << st[m] << ' ' << len[m] << endl;
        return s.substr(st[m], len[m]);
    }
};

int main(int argc, const char *argv[])
{
    string s;
    cin >> s;
    Solution so;
    cout << so.longestPalindrome(s) << endl;
    return 0;
}
