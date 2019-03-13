#include <iostream>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;
#define BALLN 10000000
int ball[BALLN];
int st[2000];
int main()
{
    int n, m;
    int okcnt = 0;
    memset(st, -1, 2000);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", ball+i);
    }
    bool first = false;
    int min = -1;
    for(int i = 0; i < n; ++i)
    {
        // cout << "i is " << i << ", ball[i] is " << ball[i] << endl;
        if(ball[i] == 0) continue;
        int bidx = ball[i] - 1;
        if(st[bidx] == -1)
        {
            // cout << bidx << " OK " << endl;
            okcnt++;
            st[bidx] = i;
            if(okcnt == m)
            {
                first = true;
                int ma = *max_element(st, st+m);
                int mi = *min_element(st, st+m);
                min = 1+(ma - mi);
            }
        }
        else
        {
            // cout << bidx << " Updated " << endl;
            st[bidx] = i;
            if(first)
            {
                int ma = *max_element(st, st+m);
                int mi = *min_element(st, st+m);
                int tmp = 1+(ma - mi);
                if(tmp < min)
                {
                    min = tmp;
                }
            }
        }
    }
    cout << min << endl;
    // if(okcnt < m)
    // {
    //     // cout << okcnt << endl;
    //     cout << "-1" << endl;
    // }
    // else
    // {
    //     // cout << ma << " " << mi << endl;
    //     cout << 1+(ma - mi) << endl;
    // }
    return 0;
}