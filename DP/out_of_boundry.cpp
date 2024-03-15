#include <bits/stdc++.h>
using namespace std;

// important came in AMAZON interview

class Solution
{
    const int Mod = 1e9 + 7;

public:
    // time ans space complexity for memoiation is :  O(m * n * maxMove)
    int solve(int m, int n, int move, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if (move < 0)
            return 0;
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        if (dp[i][j][move] != -1)
            return dp[i][j][move];
        long long up = solve(m, n, move - 1, i - 1, j, dp) % Mod;
        long long down = solve(m, n, move - 1, i + 1, j, dp) % Mod;
        long long left = solve(m, n, move - 1, i, j + 1, dp) % Mod;
        long long right = solve(m, n, move - 1, i, j - 1, dp) % Mod;

        return dp[i][j][move] = (up + down + left + right) % Mod;
    }

    // time ans space complexity for tabulation is :  O(m * n * maxMove)
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(maxMove + 2, 0)));
        dp[startRow][startColumn][1] = 1;

        for (int move = 1; move <= maxMove; move++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    long long up = (i == 0) ? 1 : dp[i - 1][j][move - 1];
                    long long down = (i == m - 1) ? 1 : dp[i + 1][j][move - 1];
                    long long left = (j == 0) ? 1 : dp[i][j - 1][move - 1];
                    long long right = (j == n - 1) ? 1 : dp[i][j + 1][move - 1];

                    dp[i][j][move] = ((up + down) % Mod + (left + right) % Mod) % Mod;
                }
            }
        }

        return dp[startRow][startColumn][maxMove] % Mod;
    }
};

int main()
{
    return 0;
}