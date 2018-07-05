#include "Solution.h"
int Solution::maxSubArray(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int m1 = INT_MIN;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            if(i == j) ans[0] = nums[i];
            else
            {
                ans[j-i] = ans[j-i-1] + nums[j];
            }
        }
        int m2 = INT_MIN;
        for(auto& i : ans)
            if(i > m2) m2 = i;
        if(m2 > m1) m1 = m2;
    }
    return m1;
}
