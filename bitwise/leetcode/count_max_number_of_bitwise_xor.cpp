#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mx = 0;
    int count = 0;

    void solve(vector<int> nums, int curr, int index, int need)
    {
        // base case
        if (curr == need)
        {
            count += 1 << (nums.size() - index);
            return;
        }
        if (index == nums.size())
            return;
        // function call for exclude
        solve(nums, curr, index + 1, need);

        // function call for include
        solve(nums, curr | nums[index], index + 1, need);
    }
    int countMaxOrSubsets(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int need = 0;
        for (auto i : nums)
        {
            need |= i;
        }
        solve(nums, 0, 0, need);
        return count;
    }
};

int main()
{
    return 0;
}