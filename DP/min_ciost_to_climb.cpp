#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &cost, vector<int> &dp, int n)
    {
        // bc
        if (n == 0)
        {
            return cost[0];
        }
        if (n == 1)
        {
            return cost[1];
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        dp[n] = cost[n] + min(solve(cost, dp, n - 1), solve(cost, dp, n - 2));
        return dp[n];
    }

    int tabulation(vector<int> &cost, int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }

    int spacoptimize(vector<int> &cost, int n)
    {
        // vector<int> dp(n + 1, -1);
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int ans = min(solve(cost, dp, n - 1), solve(cost, dp, n - 2));
        return ans;
    }
};

int main()
{
    return 0;
}