#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // dfs with backtracking simple time complexity is O(n * m * 4^(n * m) and space complexity is O(n*m) due to recursive calls
    vector<int> dr = {0, 1, 0, -1, 0}; // Change last 0 to 1
    int solve(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        // int n = grid.size();
        // int m = grid[0].size();
        if (i < 0 || j < 0 || j == m || i == n || grid[i][j] == 0)
        {
            return 0;
        }
        int sum = 0;
        int gold = grid[i][j];
        grid[i][j] = 0;
        for (int dir = 0; dir < 4; dir++)
        { // Fixed the loop condition
            sum = max(sum, solve(grid, dr[dir] + i, dr[dir + 1] + j, n, m));
        }

        grid[i][j] = gold;
        return sum + gold;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int maxGold = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                maxGold = max(maxGold, solve(grid, i, j, n, m));
            }
        }

        return maxGold;
    }
};

int main()
{
    return 0;
}