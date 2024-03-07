#include <bits/stdc++.h>
using namespace std;

// this question is a slight varient of Longest common subsequence

class Solution
{
public:
    int solve(int i, int j, string &s, string &t)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (s[i] == s[j] && i != j)
        {
            return 1 + solve(i - 1, j - 1, s, t);
        }
        return max(solve(i - 1, j, s, t), solve(i, j - 1, s, t));
    }
    int mem(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int ans = 0;
        if (s[i] == s[j] && i != j)
        {
            ans = 1 + mem(i - 1, j - 1, s, t, dp);
        }
        else
        {
            ans = max(mem(i - 1, j, s, t, dp), mem(i, j - 1, s, t, dp));
        }
        dp[i][j] = ans;
    }

    int tab(string &s, string &t)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans = 0;
                if (s[i - 1] == s[j - 1] && i != j)
                {
                    ans = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    ans = max(dp[i - 1][j], dp[i][j - 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[n][n];
    }
    int opt(string &s, string &t)
    {
        int n = s.length();
        vector<int> curr(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int ans = 0;
                if (s[i - 1] == s[j - 1] && i != j)
                {
                    ans = 1 + prev[j - 1];
                }
                else
                {
                    ans = max(prev[j], curr[j - 1]);
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return prev[n];
    }

    int LongestRepeatingSubsequence(string str)
    {
        int n = str.size();
        string txt(str.begin(), str.end());
        //  return solve(n-1, n-1, str, txt);
        //  vector<vector<int>> dp(n, vector<int> (n, -1));
        //  return mem(n-1, n-1, str, txt, dp);
        //  return tab(str, txt);
        return opt(str, txt);
    }
};

int main()
{
    return 0;
}