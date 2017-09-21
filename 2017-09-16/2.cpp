#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    auto pos = nums.end();
    for(auto it = nums.begin(); it != nums.end() - 1; ++it)
        if((pos = find(it + 1, nums.end(), target - *it)) != nums.end())
            return vector<int>{it - nums.begin(), pos - nums.begin()};
}
int main()
{
    int val;
    vector<int> nums;
    for(int i = 0; i < 10; ++i) {
        cin >> val;
        nums.push_back(val);
    }
    cin >> val;
    auto ans = twoSum(nums, val);
    cout << ans[0] << ' ' << ans[1] << endl;
}
