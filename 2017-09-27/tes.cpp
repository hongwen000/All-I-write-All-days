#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> stdlst = {5, 7, 44, 1, 35};
    list<int> l2;
    int x = 10;
    for(auto it = stdlst.begin(); it != stdlst.end();) {
        if(*it < x) {
            l2.push_back(*it);
            it = stdlst.erase(it);
        }
        else {
            ++it;
        }
    }
    for(auto it = stdlst.begin(); it != stdlst.end();++it) {
        l2.push_back(*it);
    }
    for(auto i : l2)
        cout << i << endl;
}
