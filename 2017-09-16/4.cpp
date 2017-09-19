#include <iostream>
using namespace std;
int main()
{
    int key;
    cin >> key;
    int mask = 1;
    int ans = 0;
    for(int i = 0; i < 31; ++i)
    {
        auto is_one = key & mask;
        if(is_one != 0)
            ans++;
        mask = mask << 1;
    }
    cout << ans << endl;
}
