#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    int solve(vector<int> &nums, int t, vector<int> &dp)
    {
        if (t == 0)
        {
            return 1;
        }
        if (t < 0)
        {
            return 0;
        }
        if (dp[t] != -1)
        {
            return dp[t];
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, t - nums[i], dp);
        }
        dp[t] = ans;
        return dp[t];
    }

    // tabulation
    int solve(vector<int> &nums, int t)
    {
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        // traversing from target 1 to tar
        for (int i = 1; i <= t; i++)
        {
            // traversing on nums
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[t];
    }

    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};

int main()
{
    return 0;
}