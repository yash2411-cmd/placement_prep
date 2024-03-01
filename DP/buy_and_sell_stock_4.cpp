#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // space O(K) time O(n*k)
    int opt(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max((-prices[index] + next[0][limit]), (next[1][limit]));
                    }
                    else
                    {
                        profit = max((prices[index] + next[1][limit - 1]), (next[0][limit]));
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    // solving using transaction numbers
    int solve(int index, int operation, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (operation == 2 * k)
        {
            return 0;
        }
        if (dp[index][operation] != -1)
        {
            return dp[index][operation];
        }
        int profit = 0;
        if (operation % 2 == 0)
        {
            int buy = -prices[index] + solve(index + 1, operation + 1, k, prices, dp);
            int skipbuy = solve(index + 1, operation, k, prices, dp);
            profit = max(buy, skipbuy);
        }
        else
        {
            int sell = prices[index] + solve(index + 1, operation + 1, k, prices, dp);
            int skipsell = solve(index + 1, operation, k, prices, dp);
            profit = max(sell, skipsell);
        }
        return dp[index][operation] = profit;
    }
    int tab(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int operation = 0; operation < 2 * k; operation++)
            {
                int profit = 0;
                if (operation % 2 == 0)
                {
                    int buy = -prices[index] + dp[index + 1][operation + 1];
                    int skipbuy = dp[index + 1][operation];
                    profit = max(buy, skipbuy);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][operation + 1];
                    int skipsell = dp[index + 1][operation];
                    profit = max(sell, skipsell);
                }
                dp[index][operation] = profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        // return opt(prices, k);
        // vector<vector<int>> dp(prices.size(), vector<int> (2*k, -1));
        // return solve(0, 0, k, prices, dp);
        return tab(k, prices);
    }
};

int main()
{
    return 0;
}