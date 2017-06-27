#include <iostream>
#include <regex>
using namespace std;
int main()
{
    try {
    throw 1;
    cout << "it's me" << endl;
    } catch(...) {cout << "hhh" << endl;}
    string pattern("[^c]ei");
//    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    pattern = "([[:alnum:]]+)\\.(cpp|cxx|cc)";
    regex r(pattern, regex::icase);
    smatch results;
    string test_str = "hhh.cpp hhh.cpp";
    for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it; 
            it != end_it; ++it) {
        cout << it->str(1) << endl;
    }
}
