#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity for this recursion is O(2^m*n)
    int solve(int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (i < 0 || j < 0)
            return 0;

        int up = solve(i - 1, j);
        int left = solve(i, j - 1);
        return up + left;
    }
    int mem(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }

        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = mem(i - 1, j, dp);
        int left = mem(i, j - 1, dp);
        return dp[i][j] = up + left;
    }
    int tab(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }

    int opt(int m, int n)
    {
        vector<int> prev(m, 0);
        // curr[1] = 1;
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = prev[j];
                    if (j > 0)
                        left = curr[j - 1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }

    int uniquePaths(int m, int n)
    {
        return tab(m, n);
    }
}

// using combinatorics
int
uniquePaths(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (N - r + i) / i;
    }
    return int(ans);
}

int main()
{
    return 0;
}