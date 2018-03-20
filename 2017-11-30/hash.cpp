#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int cnt = 1;
    int n;
    cin >> n;
    map<string, int> mp;
    string s;
    while(n--)
    {
        cin >> s;
        if(!mp.count(s)) mp[s] = cnt++;
        cout << s << ":" << mp[s] << endl;
    }
    return 0;
}

