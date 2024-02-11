#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp,
              int n, int i, int j, int k)
    {
        int l = i + j - k;

        // base cases
        if (i == n || j == n || k == n || l == n)
        {
            return INT_MIN;
        }
        // if the value of openeing grid is not valid then return the min
        if (grid[i][j] == -1 || grid[k][l] == -1)
        {
            return INT_MIN;
        }
        // if the we are already on the ending grid then return its value
        if (i == n - 1 && j == n - 1 && k == n - 1 && l == n - 1)
        {
            return grid[i][j];
        }

        // if the result is already calculated return it
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        int cherry = grid[i][j];
        if (i != k && j != l)
        {
            cherry += grid[k][l];
        }

        int maxCherry = max({solve(grid, dp, n, i + 1, j, k + 1),
                             solve(grid, dp, n, i + 1, j, k),
                             solve(grid, dp, n, i, j + 1, k + 1),
                             solve(grid, dp, n, i, j + 1, k)});

        if (maxCherry == INT_MIN)
        {
            dp[i][j][k] = INT_MIN;
        }
        else
        {
            dp[i][j][k] = maxCherry + cherry;
        }
        return dp[i][j][k];
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        // intialized a 3d dp

        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int ans = max(0, solve(grid, dp, n, 0, 0, 0));
        return ans;
    }
};

int main()
{
    return 0;
}