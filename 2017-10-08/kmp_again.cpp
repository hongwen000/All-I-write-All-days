#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int i, j, k;
    const char* a = "abcdabef";
    const char* b = "be";
    int n = std::strlen(a);
    int m = std::strlen(b);
    for(i = 0; i < n - m + 1; ++i) {
        k = i;
        j = 0;
        while(j < m && a[k] == b[j]) {
            ++k;
            ++j;
        }
        if(j >= m){
            std::cout << i << std::endl;
            return i;
        }
    }
    std::cout << -1 << std::endl;
    return -1;
}
