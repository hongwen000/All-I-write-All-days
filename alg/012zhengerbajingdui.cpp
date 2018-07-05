#include <iostream>
#include <vector>
using namespace std;

void insert_heap(vector<int>& v, int k)
{
    v.push_back(k);
    int x = v.size() - 1;
    while(x > 0 && v[x] > v[(x / 2)]) {
        swap(v[x], v[x/2]);
        x /= 2;
    }
}

void delete_heap(vector<int>& v) 
{
    swap(v[0], v[v.size() - 1]);
    v.erase(v.end() - 1);
    int x = 0;
    do {
        int v1 = 2 * x + 1 < v.size() ? v[2 * x + 1] : -1e9;
        int v2 = 2 * x + 2 < v.size() ? v[2 * x + 2] : -1e9;
        if(v[x] > v1 && v[x] > v2)
            break;
        int v3 = v1 < v2 ? 2 : 1;
        swap(v[x], v[2 * x + v3]);
        x = 2 * x + v3;
    }while(true);
}

int main ()
{
    vector<int> v;
    srand(time(0));
    int n = 20000;
    for(int i = 0; i < n; ++i) {
        int r = rand() % 100000;
        cout << r << ' ';
        insert_heap(v, r);
    }
    cout << endl;
    for(auto s : v)
        cout << s << ' ';
    cout << endl;
    cout << "------" << endl;
    for(int i = 0; i < n; ++i) {
        cout << v[0] << ' ';
        delete_heap(v);
    }
}
