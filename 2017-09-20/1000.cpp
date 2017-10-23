#include <list>
#include <iostream>
using namespace std;
int main() {
    int cases;
    cin >> cases;
    while(cases--){
        std::list<int> lst;
        int N, M;
        cin >> N >> M;
        for(int i = 1; i <= N; ++i)
            lst.push_back(i);
        int count = 1;
        auto it = lst.begin();
        while(lst.size() != 1) {
            if(count == M) {
                it = lst.erase(it);
                count = 1;
            }
            else {
                ++count;
                ++it;
            }
            if(it == lst.end())
                it = lst.begin();
        }
        cout << lst.front() << endl;
    }
}
