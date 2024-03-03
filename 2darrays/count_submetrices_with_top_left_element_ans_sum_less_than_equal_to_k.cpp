#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // time complexity is O(n*m) ans space complexity is O(1)
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        // iterating over the grid and changing the values to sum
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // storing sum of perivous element in the current row
                if (i > 0)
                {
                    grid[i][j] += grid[i - 1][j];
                }
                // storing sum of perivous element in the current col
                if (j > 0)
                {
                    grid[i][j] += grid[i][j - 1];
                }
                // new top-left is there and subtract the sum of previous rows and coloumn
                if (i > 0 && j > 0)
                {
                    grid[i][j] -= grid[i - 1][j - 1];
                }
                // checking for the condition to increment the ans
                if (grid[i][j] <= k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}