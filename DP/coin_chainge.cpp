#include <bits/stdc++.h>
using namespace std;
//  meomization
class Solution
{
public:
    int solve(vector<int> &coins, int amt, vector<int> &dp)
    {
        if (amt == 0)
        {
            return 0;
        }
        if (amt < 0)
        {
            return INT_MAX;
        }
        if (dp[amt] != -1)
        {
            return dp[amt];
        }
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            int ans = solve(coins, amt - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, ans + 1);
            }
        }
        dp[amt] = mini;
        return mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        // int ans = solve(coins, amount);
        // if(ans == INT_MAX){
        //     return -1;
        // }
        // return ans;
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount, dp);
        if (ans == INT_MAX)
        {
            return -1;
        }

        return ans;
    }
};

// tabulation
int tabulation(vector<int> &coins, int amt)
{
    vector<int> dp(amt + 1, INT_MAX);
    dp[0] = 0;

    // solving for each amount from bottom to up till we reach the target amount
    for (int i = 1; i <= amt; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }
    if (dp[amt] == INT_MAX)
    {
        return -1;
    }
    return dp[amt];
}

int main()
{
    return 0;
}