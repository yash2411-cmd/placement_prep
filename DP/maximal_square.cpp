#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<vector<char>> &matrix, int i, int j, int &maxi)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }
        int right = solve(matrix, i, j + 1, maxi);
        int diagonal = solve(matrix, i + 1, j + 1, maxi);
        int down = solve(matrix, i + 1, j, maxi);

        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(diagonal, down));
            maxi = max(ans, maxi);
            return ans;
        }
        else
        {
            // If the current cell is '0', the square size is 0.
            return 0;
        }
    }

    int mem(vector<vector<char>> &matrix, int i, int j, vector<vector<int>> &dp, int &maxi)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = mem(matrix, i, j + 1, dp, maxi);
        int diagonal = mem(matrix, i + 1, j + 1, dp, maxi);
        int down = mem(matrix, i + 1, j, dp, maxi);

        int ans = 0;
        if (matrix[i][j] == '1')
        {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(dp[i][j], maxi);
            return dp[i][j];
        }
        else
        {
            return 0;
        }
    }

    int tab(vector<vector<char>> &matrix, int &maxi)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min(right, min(diagonal, down));
                    maxi = max(dp[i][j], maxi);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
    // space optimized for O(M)
    int opt(vector<vector<char>> &matrix, int &maxi)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // creating two rows current and next
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int right = curr[j + 1];
                int diagonal = next[j + 1];
                int down = next[j];

                if (matrix[i][j] == '1')
                {
                    curr[j] = 1 + min(right, min(diagonal, down));
                    maxi = max(curr[j], maxi);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }
        return next[0];
    }

    // can further optimize it in O(1)
    int further_optimized(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (matrix[i][j] == '1' && i > 0 && j > 0)
                {
                    matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j])) + 1;
                }
                maxi = max(maxi, matrix[i][j] - '0');
            }
        }

        return maxi * maxi;
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        // int n = matrix.size();
        // int m = matrix[0].size();

        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // mem(matrix, 0, 0, dp, maxi);
        // return maxi*maxi;
        opt(matrix, maxi);
        return maxi * maxi;
    }
};

int main()
{
    return 0;
}