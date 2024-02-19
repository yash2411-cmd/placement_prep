#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memoization(vector<int> &nums, int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return nums[0];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int include = solve(nums, n - 2, dp) + nums[n];
        int exclude = solve(nums, n - 1, dp) + 0;
        dp[n] = max(include, exclude);
        return dp[n];
    }
    int tabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            int in = dp[i - 2] + nums[i];
            int ex = dp[i - 1] + 0;
            dp[i] = max(in, ex);
        }
        return dp[n - 1];
    }
    int rob(vector<int> &nums)
    {
        // space optimized
        int n = nums.size();
        int prev2 = 0;
        int prev1 = nums[0];
        int ans = prev1; // Initialize ans here

        for (int i = 1; i < n; i++)
        {
            int in = prev2 + nums[i];
            int ex = prev1 + 0;
            ans = max(in, ex);
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};

int main()
{
    return 0;
}