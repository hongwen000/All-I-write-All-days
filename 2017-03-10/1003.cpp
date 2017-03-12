#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int pairs;
    cin >> pairs;
    vector<int> seq;
    int input;
    map<int, int> socks;
    while(cin >> input) {
        ++socks[input];
        if(socks[input] == 2) {
        seq.push_back(socks.size());
        socks.erase(input);
        }
    }
    cout << *max_element(std::begin(seq), std::end(seq)) << endl;
    return 0;
}
