#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
using namespace std;
int tab[26];
int kind;
int get_kind() {
    kind = 0;
    for(int i = 0; i < 26; ++i)
        if(tab[i]) kind++;
    return kind;
}

int main() {
    char c;
    int spa;
    int sum = 0;
    cin >> spa;
    while(cin >> c) tab[c - 'A']++;
    sort(tab, tab + 26, greater<int>());
    while(get_kind()) {
        if(kind > spa) {
             sum += tab[kind - 1] * kind;
             for(int i = 0; i < kind; ++i)
                 tab[i] -= tab[kind];
        }
        else {
            sum += (tab[0] - 1) * (spa + 1) + 1;
            for(int i = 1; i < kind; ++i)
                if(tab[i] == tab[0])
                    sum++;
            break;
        }
    }
    cout << sum << endl;
}
