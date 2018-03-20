#include <map>
#include <iostream>
using namespace std;
int n[1000][1000];
int w[1000][1000];
bool isSym(int size) {
	for(int i = 0; i < size; ++i) {
		for(int j = 0; j < size; ++j) {
				if(n[i][j] != n[j][i])
					return false;
			}
		}
	return true;
}
bool isSelf(int size) {
	for(int i = 0; i < size; ++i)
		if(n[i][i] == 0)
			return false;
	return true;
}
bool isTrans(int size) {
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

int main()
{
    int N;
    cin >> N;
    std::map<int, int> mp;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        mp[tmp] = i;
    }
    int p;
    cin >> p;
    for (int i = 0; i < p; ++i) {
        int x, y;
        cin >> x >> y;
        n[mp[x]][mp[y]] = 1;
    }
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; j++) {
//            cout << n[i][j];
//        }
//        cout << endl;
//    }
    if(isTrans(N))
        cout << "1" << endl;
    else
        cout << "0" << endl;
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; j++) {
//            cout << w[i][j];
//        }
//        cout << endl;
//    }
}
