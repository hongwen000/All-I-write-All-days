#include <iostream>
#include <string>
using namespace std;
int * buildNext(string b) {
    int j = 0;
    int m = b.size();
    int * next = new int[m];
    int t = next[0] = -1;
    while(j < m - 1) {
        if(0 > t || b[j] == b[t]) {
            ++j;
            ++t;
            if(b[j] != b[t])
                next[j] = t;
            else
                next[j] = next[t];
        } else {
            t = next[t];
        }
    }
    return next;
}

int index2(string a, string b)
{
    int *next = buildNext(b);
    int i = 0, j = 0;
    int n = a.size();
    int m = b.size();
    while(i < n && j < m){
        if(0 > j || a[i] == b[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    delete [] next;
    if(j >= m) {
        return i - j;
    } else {
        return -1;
    }
}
int main() {
    std::cout << index2("abc", "c") << std::endl;
}
