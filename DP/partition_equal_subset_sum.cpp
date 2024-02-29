#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n^2) and space complexity is O(n)
    bool solve(int index, vector<int> &nums, int target)
    {
        if (index >= nums.size())
        {
            return false;
        }
        if (target < 0)
        {
            return false;
        }
        if (target == 0)
        {
            return true;
        }
        bool in = solve(index + 1, nums, target - nums[index]);
        bool ex = solve(index + 1, nums, target);
        return in || ex;
    }
    // time complexity is O(n*target) and space complexity is O(n*target)
    bool mem(int index, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (index >= nums.size())
        {
            return false;
        }
        if (target < 0)
        {
            return false;
        }
        if (target == 0)
        {
            return true;
        }
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        bool in = mem(index + 1, nums, target - nums[index], dp);
        bool ex = mem(index + 1, nums, target, dp);
        return dp[index][target] = in || ex;
    }

    // time complexity is O(n*target) and space complexity is O(n*target)
    bool tab(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true; // Base case: target 0 can be achieved by not selecting any element
        }

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 0; t <= target; t++)
            {
                bool in = false;
                if (t - nums[index] >= 0)
                {
                    in = dp[index + 1][t - nums[index]]; // Check if current number can be included
                }
                bool ex = dp[index + 1][t]; // Check if current number is excluded
                dp[index][t] = in || ex;    // Current state is achievable if either inclusion or exclusion is possible
            }
        }
        return dp[0][target];
    }
    // time complexity is O(n*target) and space complexity is O(target)
    bool opt(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> curr(target + 1, 0);
        vector<int> next(target + 1, 0);
        curr[0] = 1;
        next[0] = 1;

        for (int index = n - 1; index >= 0; index--)
        {
            for (int t = 0; t <= target; t++)
            {
                bool in = false;
                if (t - nums[index] >= 0)
                {
                    in = next[t - nums[index]]; // Check if current number can be included
                }
                bool ex = next[t];  // Check if current number is excluded
                curr[t] = in || ex; // Current state is achievable if either inclusion or exclusion is possible
            }
            next = curr;
        }
        return next[target];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;
        // vector<vector<int>> dp(nums.size(), vector<int>(target+1, -1));
        // return mem(0,nums, sum/2, dp);
        return opt(nums, target);
    }
};

int main()
{
    return 0;
}