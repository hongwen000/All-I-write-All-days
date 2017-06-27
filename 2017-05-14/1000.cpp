#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int ans = 0;
    int n = 10;
    for(int i = 1; i <= n-2; i++)
        for(int j = i + 1; j <= n; j++)
            ans += 1;
    cout << ans << endl;
    return 0;
}
