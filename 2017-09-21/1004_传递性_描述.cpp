#include <map>
#include <iostream>
using namespace std;
int n[1000][1000];
int w[1000][1000];
bool isReSym(int size) {
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
    int size;
    cin >> size;
    int tmp;
    map<int, int> mp;
    for(int i = 0; i < size; ++i) {
        cin >> tmp;
        mp[tmp] = i;
    }
    cin >> tmp;
    int a, b;
    while(tmp--) {
        cin >> a >> b;
        n[mp[a]][mp[b]] = 1;
    }
    if(isTrans(size))
        cout << "1" << endl;
    else
        cout << "0" << endl;
}
