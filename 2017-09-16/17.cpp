#include <vector>
#include <iostream>
using namespace std;
int main()
{
    auto v = std::vector{5, 2, 4, 2};
    for(auto i : v) 
        cout << i << endl;
}
