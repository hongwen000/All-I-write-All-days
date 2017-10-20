#include <string>
#include <iostream>
using String = std::string;
String::size_type bf0A(const String& Pattern, const String& Text) {
    using ss_t = String::size_type;
    ss_t m = Pattern.size();
    ss_t n = Text.size();
    ss_t i, j;
    for(i = 0; i < n - m + 1; ++i) {
        for(j = 0; j < m; ++j) {
            if(Text[i + j] != Pattern[j]) {
                break;
            }
        }
        if(j >= m)
            return i;
    }
    return -1;
}

String::size_type bf1A(const String& Pattern, const String& Text) {
    using ss_t = String::size_type;
    ss_t m = Pattern.size();
    ss_t n = Text.size();
    ss_t i, k;
    for(i = 0; i < n - m + 1; ++i) {
        k = 0;
        while(k < m && Pattern[k] == Text[i + k]) {
            ++k;
        }
        if(k >= m)
            return i;
    }
    return -1;
}
String::size_type bf2A(const String& Pattern, const String& Text) {
    using ss_t = String::size_type;
    ss_t m = Pattern.size();
    ss_t n = Text.size();
    ss_t i = 0, k = 0;
    while(k < m && i < n) {
        if(Pattern[k] == Text[i]) {
            ++k;
            ++i;
        }
        else {
            i = i - k + 1;
            k = 0;
        }
    }
    if(k >= m)
        return i - k;
    return -1;
}

int main() {
    String a = "acdbcdefacd";
    String b = "b";
    std::cout << (bf2A(b, a) == (String::size_type) -1) << std::endl;
}
