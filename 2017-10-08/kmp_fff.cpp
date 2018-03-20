#include <iostream>
#include <string>
using namespace std;
int * buildNext(string b) {
    int m = b.size();
    int * next = new int[m];
    int p = 0;
    int t;
    t = next[0] = -1;
    while(p < m - 1) {
        if(t < 0 || b[p] == b[t]) {
            ++p;
            ++t;
            if(b[p] != b[t]) {
                next[p] = t;
            } else {
                next[p] = next[t];
            }
        } else {
            t = next[t];
        }
    }
    return next;
}

int index(string a, string b) {
    int * next = buildNext(b);
    int i = 0, j = 0;
    int n = a.size();
    int m = b.size();
    while(i < n && j < m) {
        if(j < 0 || a[i] == b[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    delete [] next;
    if(j >= m)
        return i - j;
    else
        return -1;
}
int main(){
    std::cout << index("abc", "c");
}
