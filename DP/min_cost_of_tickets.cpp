#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &days, vector<int> &costs, int index)
    {
        int n = days.size();
        // base case
        if (index >= n)
        {
            return 0;
        }
        int oneday = costs[0] + solve(days, costs, index + 1);
        int i;
        // making sure to cover the next seven days
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;
        int sevenday = costs[1] + solve(days, costs, i);

        // for 30 days
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;
        int thirtyday = costs[2] + solve(days, costs, i);

        return min(oneday, min(sevenday, thirtyday));
    }
    int mem(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp)
    {
        // base case
        if (index >= n)
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int oneday = costs[0] + mem(n, days, costs, index + 1, dp);
        int i;
        // making sure to cover the next seven days
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;
        int sevenday = costs[1] + mem(n, days, costs, i, dp);

        // for 30 days
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;
        int thirtyday = costs[2] + mem(n, days, costs, i, dp);

        dp[index] = min(oneday, min(sevenday, thirtyday));
        return dp[index];
    }

    int tab(int n, vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(n + 1, INT_MAX);
        // bc
        dp[n] = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            int oneday = costs[0] + dp[j + 1];
            int i;
            // making sure to cover the next seven days
            for (i = j; i < n && days[i] < days[j] + 7; i++)
                ;
            int sevenday = costs[1] + dp[i];

            // for 30 days
            for (i = j; i < n && days[i] < days[j] + 30; i++)
                ;
            int thirtyday = costs[2] + dp[i];

            dp[j] = min(oneday, min(sevenday, thirtyday));
        }
        return dp[0];
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        // vector<int>dp(n+1,-1);

        return tab(n, days, costs);
    }
};

int main()
{
    return 0;
}