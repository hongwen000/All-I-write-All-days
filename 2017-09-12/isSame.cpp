#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
class Same {
    public :static bool comp(vector<int> a, vector<int> b) {
       std::multiset<int> avail;
       if(a.empty() != b.empty())
       	return false;
       for(auto i : a)
       	avail.insert(i * i);
       for(auto i : b) {
        cout << "looking for " << i << endl;
        auto it = avail.find(i);
       	if(it == avail.end())
        	return false;
        else {
          avail.erase(it);
          cout << "erased " << *it << endl;
        }
       }
       return true;
    }
};

int main(){
        vector<int> a1 {121, 144, 19, 161, 19, 144, 19, 11};
        vector<int> b2 {11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19};
        bool r = Same::comp(a1, b2); // true
        cout << r << endl;
}
