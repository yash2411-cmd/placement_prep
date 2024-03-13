#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mem(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && arr[i][j] == 1)
        {
            return 0;
        }

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
        int up = mem(i - 1, j, arr, dp);
        int left = mem(i, j - 1, arr, dp);
        return dp[i][j] = up + left;
    }

    int opt(int m, int n, vector<vector<int>> &arr)
    {
        if (arr[0][0] == 1)
            return 0;
        vector<int> prev(m, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    curr[j] = 1;
                else if (arr[i][j] == 1)
                    curr[j] = 0;
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

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        return opt(n, m, obstacleGrid);
    }
};

int main()
{
    return 0;
}