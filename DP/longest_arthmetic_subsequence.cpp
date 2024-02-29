#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int diff, vector<int> &nums)
    {
        // backward check yaha lagega
        if (index < 0)
        {
            return 0;
        }
        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve(j, diff, nums));
            }
        }
        return ans;
    }
    // top down solution is also not able to solve all the test cases
    int mem(int index, int diff, vector<int> &nums, unordered_map<int, int> dp[])
    {
        // backward check yaha lagega
        if (index < 0)
        {
            return 0;
        }
        if (dp[index].count(diff))
        {
            return dp[index][diff];
        }
        int ans = 0;
        for (int j = index - 1; j >= 0; j--)
        {
            if (nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + mem(j, diff, nums, dp));
            }
        }
        return dp[index][diff] = ans;
    }

    // time complexity O(n^2) and same for space
    // can further be optimized for space to O(n) using formula of ap = a+c/2 = b;

    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }
        int ans = 0;
        unordered_map<int, int> dp[n + 1];
        // for(int i =0;i<n;i++){
        //     for(int j = i+1; j<n;j++){
        //         // why plus 2, because we have already choosen 2 numbers for ap
        //         ans = max(ans, 2+ mem(i, nums[j]- nums[i], nums, dp));
        //     }
        // }
        // return ans;

        // bottom up
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                int cnt = 1;
                // check if ans is already present
                if (dp[j].count(diff))
                {
                    cnt = dp[j][diff];
                }
                dp[i][diff] = cnt + 1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}