#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time and space complexity is O(n*m)
    void count(vector<vector<int>> &matrix, vector<vector<int>> &dp, int n, int m)
    {
        // for first row and first coloumn if there is 1 at any index that contributes to ans
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 1)
            {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == 1)
            {
                dp[0][i] = 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    // if the all are in boundries;
                    if (i >= 0 && i < n && j >= 0 && j < m && dp[i - 1][j] > 0 && dp[i - 1][j - 1] > 0 && dp[i][j - 1] > 0)
                    {
                        dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    }
                    else
                    {
                        // simply add one to ans
                        dp[i][j]++;
                    }
                }
            }
        }
    }
    int countSquares(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        count(matrix, dp, n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}