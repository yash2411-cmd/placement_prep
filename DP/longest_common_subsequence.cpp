#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string a, string b, int i, int j)
    {
        if (i == a.size())
        {
            return 0;
        }
        if (j == b.size())
        {
            return 0;
        }
        if (a[i] == b[j])
        {
            return 1 + solve(a, b, i + 1, j + 1);
        }
        else
        {
            return max((solve(a, b, i, j + 1)), (solve(a, b, i + 1, j)));
        }
    }
    int mem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.size())
        {
            return 0;
        }
        if (j == b.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j])
        {
            ans = 1 + mem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            ans = max((mem(a, b, i, j + 1, dp)), (mem(a, b, i + 1, j, dp)));
        }
        return dp[i][j] = ans;
    }

    int tab(string a, string b)
    {
        int n = a.length();
        int m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    // space : O(min(n, m)) time: O(nxm)
    int opt(string &a, string &b)
    {
        int n = a.length();
        int m = b.length();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = 1 + next[j + 1];
                }
                else
                {
                    ans = max(next[j], curr[j + 1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        // return solve(text1, text2, 0, 0);
        // vector<vector<int>> dp(text1.size(), vector<int> (text2.size(), -1));
        // return mem(text1, text2, 0, 0, dp);
        // return tab(text1, text2);
        return opt(text1, text2);
    }
};

int main()
{
    return 0;
}