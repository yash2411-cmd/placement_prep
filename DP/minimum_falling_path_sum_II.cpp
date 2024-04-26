#include <bits/stdc++.h>
using namespace std;

// time and space compexity if O(n^3)
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = grid[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> prev(n);
            for (int j = 0; j < m; j++)
            {
                prev[j] = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (j != k)
                    {
                        prev[j] = min(prev[j], grid[i][j] + dp[k]);
                    }
                }
            }
            dp = prev;
        }
        int ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};

// time complexity is O(n^2) and space is constant
class Solution
{
public:
    int dp[201][201];
    int solve(int row, int col, vector<vector<int>> &grid)
    {
        if (row >= grid.size())
        {
            return 0;
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int ans = INT_MAX;
        for (int i = 0; i < grid.size(); i++)
        {
            if (col != i)
            {
                ans = min(ans, grid[row][i] + solve(row + 1, i, grid));
            }
        }
        return dp[row][col] = ans;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = INT_MAX;
        for (int col = 0; col < n; col++)
        {
            ans = min(ans, grid[0][col] + solve(1, col, grid));
        }
        return ans;
    }
};
int main()
{
    return 0;
}