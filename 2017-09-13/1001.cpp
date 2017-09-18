#include <list>
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int tmp;
    list<int> lst;
    while(N--) {
        cin >> tmp;
        lst.push_back(tmp);
    }
    for(auto it = lst.begin(); it != lst.end();)
    {
        if(*it == 0)
            ++it;
        else {
            list<int>::iterator it_test_end = it;
            list<int>::iterator it_test_begin_not_end = it;
            if(it == lst.begin() && ++it_test_begin_not_end != lst.end()) {
                if(lst.size() > 1)
                    it = lst.erase(it);
                it = lst.erase(it);
            }
            else if(++it_test_end == lst.end()) {
                if(lst.size() > 1)
                    it = lst.erase(--it);
                it = lst.erase(it);
            }
            else{
                it = lst.erase(--it);
                it = lst.erase(it);
                it = lst.erase(it);
            }
        }
    }
    cin >> tmp;
    if(tmp > lst.size())
        cout << "0";
    else
        cout << "1";
}
