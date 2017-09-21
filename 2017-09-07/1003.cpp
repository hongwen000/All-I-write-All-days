#include <iostream>
#include <vector>
using namespace std;
int binarySearch(const vector<int> & v, int x)
{
    int high       = v.size();
    int low        = 0;
    while(low < high){
        int mid = (high + low) / 2;
        if(v[mid] == x)
            return true;
        if(x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return false;
}
int main(){
    vector<int> v{0, 1, 2, 3, 4, 5};
    cout << binarySearch(v, 8) << endl;
}
