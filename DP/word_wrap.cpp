#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[505][2005];
    int solve(int index, int rem, vector<int> &nums, int &k)
    {
        // if my index has reached at last we return 0;
        if (index == nums.size())
        {
            return 0;
        }
        // checking if  the value is already calculated or not.
        if (dp[index][rem] != -1)
        {
            return dp[index][rem];
        }
        int ans = 0;
        // if the current length of characters are greater than the remaining spaces than simply add the cost of remaining spaces and call for next index and update the
        // remaining spaces by the spaces we have spaces we used and -1 for mid space
        if (nums[index] > rem)
        {
            ans = (rem + 1) * (rem + 1) + solve(index + 1, k - nums[index] - 1, nums, k);
        }
        else
        {
            // else we have two ways to either to put the chars in same line or on the next line
            // if we put them in the next line we again calculate the new remaining and call for next
            int a = (rem + 1) * (rem + 1) + solve(index + 1, k - nums[index] - 1, nums, k);
            // next choice is to put the number in the same line and we don't add any cost
            int b = solve(index + 1, rem - nums[index] - 1, nums, k);
            ans = min(a, b);
        }
        dp[index][rem] = ans;
        return dp[index][rem];
    }
    int solveWordWrap(vector<int> nums, int k)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, nums, k);
    }

    int main()
    {
        return 0;
    }