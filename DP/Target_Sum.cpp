#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int total = 0;
    // int ans =0;
    // void solve(vector<int> &nums, int target, int index, int  sum){
    //     if(index == nums.size()){
    //         if(sum == target){
    //             ans++;
    //         }
    //     }
    //     else{
    //         solve(nums, target, index+1, sum-nums[index]);
    //         solve(nums, target, index+1, sum +nums[index]);
    //     }

    // }
    // time and space complexity for memo is O(n*t)
    int mem(vector<int> &nums, int target, int index, int sum, vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            if (sum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (dp[index][sum + total] != INT_MIN)
            {
                return dp[index][sum + total];
            }

            int add = mem(nums, target, index + 1, sum + nums[index], dp);
            int sub = mem(nums, target, index + 1, sum - nums[index], dp);
            return dp[index][sum + total] = add + sub;
        }
    }

    int tab(vector<int> &nums, int target)
    {
        int n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total * 2 + 1, INT_MIN));
        dp[n - 1][sum] = 0;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        // solve(nums, target , 0, 0);
        // return ans;

        int n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(total * 2 + 1, INT_MIN));
        return mem(nums, target, 0, 0, dp);
    }
};

int main()
{
    return 0;
}