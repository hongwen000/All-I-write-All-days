#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int i, j, k;
    const char *a = "abcd";
    const char *b = "cd";
    int n = std::strlen(a);
    int m = std::strlen(b);
    for(i = 0; i < n - m + 1; ++i) {
        j = 0;
        k = i;
        while(j < m && a[k] == b[j]) {
            ++k;
            ++j;
        }
        if(j >= m) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
