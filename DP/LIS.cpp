#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, vector<int> &nums, int curr, int prev)
    {
        if (curr == n)
        {
            return 0;
        }

        // include
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            take = 1 + solve(n, nums, curr + 1, curr);
        }

        // exclude
        int not_take = 0 + solve(n, nums, curr + 1, prev);
        return max(take, not_take);
    }
    int mem(int n, vector<int> &nums, int curr, int prev, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }
        // include
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev])
        {
            take = 1 + mem(n, nums, curr + 1, curr, dp);
        }

        // exclude
        int not_take = 0 + mem(n, nums, curr + 1, prev, dp);
        dp[curr][prev + 1] = max(take, not_take);
        return dp[curr][prev + 1];
    }

    int tab(int n, vector<int> &nums)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                // exclude
                int not_take = 0 + dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }
    int opt(int n, vector<int> &nums)
    {
        vector<int> currrow(n + 1, 0);
        vector<int> nextrow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int take = 0;
                if (prev == -1 || nums[curr] > nums[prev])
                {
                    take = 1 + nextrow[curr + 1];
                }

                // exclude
                int not_take = 0 + nextrow[prev + 1];
                currrow[prev + 1] = max(take, not_take);
            }
            nextrow = currrow;
        }
        return nextrow[0];
    }
    // tc O(NlogN) and sc O(n)
    int solveBS(int n, vector<int> &nums)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // find the index of just greater element
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int> &nums)
    {
        // return solve(nums.size(), nums, 0, -1);
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n+1, -1));
        // return mem(n, nums, 0, -1, dp);
        // return tab(n, nums);
        // return opt(n, nums);
        return solveBS(n, nums);
    }
};

int main()
{
    return 0;
}