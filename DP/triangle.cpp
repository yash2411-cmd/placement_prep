#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &t, int row, int col, vector<vector<int>> &dp)
    {
        if (row == t.size() - 1)
        {
            return dp[row][col] = t[row][col];
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int left = solve(t, row + 1, col, dp);
        int right = solve(t, row + 1, col + 1, dp);

        return dp[row][col] = t[row][col] + min(left, right);
    }
    // time and space complexity of this solution is O(n^2)
    int tab(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // fill the dp last with last row
        for (int j = 0; j < n; ++j)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
    // optimized for space complexity O(n)
    int opt(vector<vector<int>> &t)
    {
        int n = t.size();
        vector<int> dp(n, 0);
        for (int j = 0; j < n; ++j)
        {
            dp[j] = t[n - 1][j];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = t[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        // int n = triangle.size();
        // // int m = triangle[0].size();
        // vector<vector<int>> dp(n, vector<int> (n, -1));
        // return solve(triangle, 0, 0, dp);
        return tab(triangle);
    }
};

int main()
{
    return 0;
}