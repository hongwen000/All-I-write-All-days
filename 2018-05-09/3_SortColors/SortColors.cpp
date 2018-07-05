#include "Solution.h"
void Solution::sortColors(vector<int>& nums)
{
    int C[3] = {0};
    int n = nums.size();
    for(int i = 0; i < n; ++i)
    {
        C[nums[i]]++;
    }
    int p = 0;
    for(int i = 0; i < 3; ++i)
    {
        while(C[i]--)
        {
            nums[p++] = i;
        }
    }
}
