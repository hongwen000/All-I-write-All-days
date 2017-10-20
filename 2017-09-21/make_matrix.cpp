#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef set<int> Set;

typedef set<pair<int, int>> Relation;

typedef vector<vector<int>> Matrix;

void toMatrix(const Relation& R, const Set& A, Matrix& n, Matrix& w)
{
    map<int, int> mp;
    set<int>::iterator it;
    int i = 0;
    for (it = A.begin(); it != A.end(); ++it) {
        mp[*it] = i;
        ++i;
    }
    pair tmp;
    map<int, int> iterator it2;
    for (it2 = mp.begin(); it2 != mp.end(); ++it2) {
        tmp = *it;
        a = tmp.first;
        b = tmp.second;
        n[mp[a]][mp[b]] = 1;
    }
}

bool reflexive(const Relation& R, const Set& A)
{
    Matrix n[1000][1000];
    Matrix w[1000][1000];
}
