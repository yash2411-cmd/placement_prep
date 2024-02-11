#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<int>> &grid, vector<vector<vector<int>>> &dp,
              int row, int col, int i, int j, int k)
    {
        if (i == row)
        {
            return 0;
        }
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        int cherry = grid[i][j];
        if (j != k)
        {
            cherry += grid[i][k];
        }

        // Explore all possible moves for both robots
        int maxCherry = 0;
        for (int x = -1; x <= 1; ++x)
        {
            for (int y = -1; y <= 1; ++y)
            {
                int nj = j + x;
                int nk = k + y;

                // Check if robots stay within the grid
                if (nj >= 0 && nj < col && nk >= 0 && nk < col)
                {
                    maxCherry = max(maxCherry, solve(grid, dp, row, col, i + 1, nj, nk));
                }
            }
        }
        return dp[i][j][k] = maxCherry + cherry;
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        int ans = max(0, solve(grid, dp, row, col, 0, 0, col - 1));
        return ans;
    }
};
int main()
{
    return 0;
}