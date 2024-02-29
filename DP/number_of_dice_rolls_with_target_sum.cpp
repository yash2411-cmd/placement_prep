#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1000000007;
    int solve(int n, int k, int target)
    {
        if (target < 0)
        {
            return 0;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (target == 0 && n != 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + solve(n - 1, k, target - i)) % mod;
        }
        return ans;
    }
    //   time complexity is O(n*m*X) and space is O(n*x)
    int mem(int n, int k, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
        {
            return 0;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (target == 0 && n != 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + mem(n - 1, k, target - i, dp)) % mod;
        }
        return dp[n][target] = ans;
    }

    int tab(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int dice = 1; dice <= n; dice++)
        {
            for (int t = 1; t <= target; t++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (t - i >= 0)
                    {
                        ans = (ans + dp[dice - 1][t - i]) % mod;
                    }
                }
                dp[dice][t] = ans;
            }
        }
        return dp[n][target];
    }
    int opt(int n, int k, int target)
    {
        vector<int> curr(target + 1, 0);
        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        for (int dice = 1; dice <= n; dice++)
        {
            for (int t = 1; t <= target; t++)
            {
                int ans = 0;
                for (int i = 1; i <= k; i++)
                {
                    if (t - i >= 0)
                    {
                        ans = (ans + prev[t - i]) % mod;
                    }
                }
                curr[t] = ans;
            }
            prev = curr;
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target)
    {
        // return solve(n, k, target);
        // vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return mem(n, k, target, dp);
        // return tab(n,k,target);
        return opt(n, k, target);
    }
};

int main()
{
    return 0;
}