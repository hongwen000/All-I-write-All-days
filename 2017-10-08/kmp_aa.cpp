#include <iostream>
#include <string>
using namespace std;

int index2(string a, string b) {
    int i = 0, j = 0;
    int n = a.size();
    int m = b.size();
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            ++i;
            ++j;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= m)
        return i - j;
    else
        return -1;
}

int main() {
    string a = "abc";
    string b = "c";
    std::cout << index2(a, b) << std::endl;
}
