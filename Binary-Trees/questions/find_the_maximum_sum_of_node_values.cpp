#include <bits/stdc++.h>
using namespace std;

// top down dp
class Solution
{
public:
    // time complexity is O(n) and space complexity is O(n)
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return solve(0, 1, nums, k, dp);
    }

private:
    long long solve(int index, int isEven, vector<int> &nums, int k, vector<vector<long long>> &dp)
    {
        if (index == nums.size())
        {
            return isEven == 1 ? 0 : INT_MIN;
        }
        if (dp[index][isEven] != -1)
        {
            return dp[index][isEven];
        }
        long long notchange = nums[index] + solve(index + 1, isEven, nums, k, dp);
        long long change = (nums[index] ^ k) + solve(index + 1, isEven ^ 1, nums, k, dp);

        return dp[index][isEven] = max(notchange, change);
    }
};

int main()
{
    return 0;
}