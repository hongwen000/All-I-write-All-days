#include <utility>
#include <vector>
#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef set<int> Set;

typedef set<pair<int, int>> Relation;

typedef vector<vector<int>> Matrix;

typedef int (*mt)[1000] ;

bool isReSym(int size, mt n) {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
			if(i == j)
				continue;
			else {
				if(n[i][j] && n[j][i])
					return false;
			}
		}
	}
	return true;
}
bool isSelf(int size, mt n) {
	for(int i = 0; i < size; ++i)
		if(n[i][i] == 0)
			return false;
	return true;
}
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
    for (it2 = R.begin(); it2 != R.end(); ++it2)
        n[mp[it2->first]][mp[it2->second]] = 1;
}

bool isSym(int size, mt n) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
                if(n[i][j] != n[j][i])
                    return false;
        }
    }
    return true;
}

bool reflexive(const Relation& R, const Set& A)
{
    int n[1000][1000];
    int w[1000][1000];
    for(int i = 0; i < 1000; ++i)
        for(int j = 0; j < 1000; ++j) {
            n[i][j] = 0;
            w[i][j] = 0;
        }
    toMatrix(R, A, n);
    //for(unsigned i = 0; i < A.size(); ++i) {
    //    for(unsigned j = 0; j < A.size(); ++j)
    //        cout << n[i][j];
    //    cout << endl;
    //}
    return isSelf(A.size(), n);
}

int main() {
    int cases = 100;
    cin >> cases;
    while(cases--) {
    int N;
    cin >> N;
    if(N == 0)
        continue;
    Set a;
    int ele;
    while(N--) {
        cin >> ele;
        a.insert(ele);
    }
    std::pair<int, int> rel;
    int P;
    cin >> P;
    if(P == 0)
        continue;
    Relation b;
    while(P--) {
        int x, y;
        cin >> x >> y;
        b.insert(std::make_pair(x, y));
    }
    cout << reflexive(b, a) << endl;
}
}
