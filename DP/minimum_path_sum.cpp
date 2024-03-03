#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // Get the number of rows in the grid
        int n = grid.size();
        // Get the number of columns in the grid
        int m = grid[0].size();
        // Create a 2D dynamic programming table initialized with 0s
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));

        // Loop through each cell in the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // If it's the top-left cell, assign its value to dp
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                // If it's in the first row, calculate its value based on the previous cell in the same row
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                // If it's in the first column, calculate its value based on the previous cell in the same column
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                // Otherwise, calculate its value based on the minimum of the values from the cell above and the cell to the left
                else
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Return the minimum path sum, which is stored in the bottom-right cell of the dp table
        return dp[n - 1][m - 1];
    }
};

int main()
{
    return 0;
}