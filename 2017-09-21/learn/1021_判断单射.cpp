#include <set>
#include <iostream>
using namespace std;
int main()
{
    int cases;
    cin >> cases;
    while(cases--) {
        int a, b;
        cin >> a >> b;
        std::multiset<int> s;
        std::set<int> vars;
        while(b--){
            int x, y;
            cin >> x >> y;
                s.insert(y);
        }
        bool flag = true;
        for(int i = 1; i <= a; ++i) {
            if(s.count(i) > 1) {
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Yes" <<endl;
        else
            cout << "No" << endl;
    }
}
