#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
        {
            return 0;
        }
        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;
        if (buy)
        {
            profit = max((-prices[index] + solve(index + 1, 0, prices, dp)), (solve(index + 1, 1, prices, dp)));
        }
        else
        {
            profit = max((prices[index] + solve(index + 2, 1, prices, dp)), (solve(index + 1, 0, prices, dp)));
        }
        return dp[index][buy] = profit;
    }

    int tab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max((-prices[index] + dp[index + 1][0]), (dp[index + 1][1]));
                }
                else
                {

                    profit = max((prices[index] + dp[index + 2][1]), (dp[index + 1][0]));
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }

    // much more readablity
    int opt(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            int profit = 0;
            dp[index][1] = max((-prices[index] + dp[index + 1][0]), (dp[index + 1][1]));
            dp[index][0] = max((prices[index] + dp[index + 2][1]), (dp[index + 1][0]));
        }
        return dp[0][1];
    }

    int maxProfit(vector<int> &prices)
    {
        // vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        // return solve(0, 1, prices, dp);
        return tab(prices);
    }
};

int main()
{
    return 0;
}