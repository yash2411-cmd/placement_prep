#include <bits/stdc++.h>
using namespace std;

// based on 0 1 knapsack pattern (include, exclude)
class Solution
{
public:
    int solve(vector<int> &s, int index, int time)
    {
        if (index == s.size())
        {
            return 0;
        }

        int include = s[index] * (time + 1) + solve(s, index + 1, time + 1);
        int exclude = 0 + solve(s, index + 1, time);
        return max(include, exclude);
    }
    int mem(vector<int> &s, int index, int time, vector<vector<int>> &dp)
    {
        if (index == s.size())
        {
            return 0;
        }
        if (dp[index][time] != -1)
        {
            return dp[index][time];
        }

        int include = s[index] * (time + 1) + mem(s, index + 1, time + 1, dp);
        int exclude = 0 + mem(s, index + 1, time, dp);
        dp[index][time] = max(include, exclude);
        return dp[index][time];
    }
    int tab(vector<int> &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = s[index] * (time + 1) + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];
                dp[index][time] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int opt(vector<int> &s)
    {
        int n = s.size();
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int time = index; time >= 0; time--)
            {
                int include = s[index] * (time + 1) + next[time + 1];
                int exclude = 0 + next[time];
                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int> &satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        // return solve(satisfaction, 0, 0);
        // int n = satisfaction.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        // return mem(satisfaction, 0,0,dp);
        // return tab(satisfaction);
        return opt(satisfaction);
    }
};
int main()
{
    return 0;
}