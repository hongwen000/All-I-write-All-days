#include <algorithm>
#include <list>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() { 
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        list<int> lst;
        for(int i = 1; i <= n; ++i)
            lst.push_back(i);
        while(m--) {
            int p1, p2, p3;
            cin >> p1 >> p2 >> p3;
            auto pos = std::find(lst.begin(), lst.end(), p3);
            auto pos0 = std::find(lst.begin(), lst.end(), p2);
            if(p1 == 1) {lst.insert(pos, p2); lst.erase(pos0);}
            else        {lst.insert(++pos, p2); lst.erase(pos0);}
        }
        for(auto i : lst)
            cout << i << ' ';
        cout << endl;
    }
    return 0; 
}
