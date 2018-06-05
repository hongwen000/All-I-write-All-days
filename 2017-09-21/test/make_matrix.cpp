#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef set<int> Set;

typedef set<pair<int, int>> Relation;

typedef vector<vector<int>> Matrix;

typedef vector<vector<int> > mt;
bool isTrans(int size, mt n, mt w) {

    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            w[i][j] = n[i][j];
    for(int k = 0; k < size; ++k)
        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size; ++j)
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            if(w[i][j] != n[i][j])
                return false;
    return true;
}
void toMatrix(const Relation& R, const Set& A, mt n)
{
    map<int, int> mp;
    set<int>::iterator it;
    int i = 0;
    for (it = A.begin(); it != A.end(); ++it) {
        mp[*it] = i;
        ++i;
    }
    set<pair<int, int> >::iterator it2;
    for (it2 = R.begin(); it2 != R.end(); ++it2) {
        int a, b;
        a = it2->first;
        b = it2->second;
        n[mp[a]][mp[b]] = 1;
    }
}

bool transitive(const Relation& R, const Set& A)
{
    vector<vector<int> > n;
    vector<vector<int> > w;
    toMatrix(R, A, n);

    if(isTrans(A.size(), n, w))
        return true;
    else
        return false;
}

