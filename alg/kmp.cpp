#include <iostream>
#include <string>
#include <vector>
#include <array>
using String = std::string;
std::vector<int> buildNext(const String& Pattern) {
    int m = Pattern.size(), j = 0, t = -1;
    std::vector<int> next(Pattern.size());
    next[0] = -1;
    while(j < m - 1) {
        if(0 > t || Pattern[j] == Pattern[t]) {
            next[++j] = ++t;
        } else {
            t = next[t];
        }
    }
    return next;
}

int kmp(const String& Pattern, const String& Text) {
    auto next = buildNext(Pattern);
    for(auto i : next) 
        std::cout << i << ' ';
    std::cout << std::endl;
    int m = Pattern.size();
    int n = Text.size();
    int i = 0, j = 0;
    while(j < m && i < n) {
        if(0 > j || Pattern[j] == Text[i]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if(j >= m)
        return i - j;
    else 
        return -1;
}

int main() {
    String a = "defghijk";
    String b = "abc";
    std::cout << kmp(b, a) << std::endl;
}
