#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(3^n) and space is also O(n)
    int solve(vector<vector<int>> &arr, int i, int j)
    {
        int n = arr.size();
        int m = arr[0].size();
        if (j < 0 || j >= m)
        {
            return 1e8;
        }
        if (i == 0)
        {
            return arr[0][j] + min({0, INT_MAX});
        }
        int s = arr[i][j] + solve(arr, i - 1, j);
        int leftdiag = arr[i][j] + solve(arr, i - 1, j - 1);
        int rightdiag = arr[i][j] + solve(arr, i - 1, j + 1);

        return min(s, min(leftdiag, rightdiag));
    }
    // time complexity is O(nxm) and space is also O(nxm)+O(n)
    int mem(vector<vector<int>> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= arr[0].size())
        {
            return 1e8;
        }
        if (i == 0)
        {
            return arr[0][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int s = arr[i][j] + mem(arr, i - 1, j, dp);
        int leftdiag = arr[i][j] + mem(arr, i - 1, j - 1, dp);
        int rightdiag = arr[i][j] + mem(arr, i - 1, j + 1, dp);

        return dp[i][j] = min(s, min(leftdiag, rightdiag));
    }
    // time complexity is O(nxm) and space is also O(nxm)
    int tab(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int j = 0; j < m; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int s = matrix[i][j] + dp[i - 1][j];
                int leftdiag = matrix[i][j];
                if (j - 1 >= 0)
                    leftdiag += dp[i - 1][j - 1];
                else
                    leftdiag += 1e8;
                int rightdiag = matrix[i][j];
                if (j + 1 < m)
                    rightdiag += dp[i - 1][j + 1];
                else
                    rightdiag += 1e8;
                dp[i][j] = min(s, min(leftdiag, rightdiag));
            }
        }
        int ans = dp[n - 1][0];
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
    // time complexity is O(nxm) and space is also O(m)
    int opt(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0);
        vector<int> curr(m, 0);

        for (int j = 0; j < m; j++)
        {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int s = matrix[i][j] + prev[j];
                int leftdiag = matrix[i][j];
                if (j - 1 >= 0)
                    leftdiag += prev[j - 1];
                else
                    leftdiag += 1e8;
                int rightdiag = matrix[i][j];
                if (j + 1 < m)
                    rightdiag += prev[j + 1];
                else
                    rightdiag += 1e8;
                curr[j] = min(s, min(leftdiag, rightdiag));
            }
            prev = curr;
        }
        int ans = prev[0];
        for (int i = 0; i < m; i++)
        {
            ans = min(ans, prev[i]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // int ans = 1e8;
        // for(int j=0;j<m;j++){
        //     ans = min(ans, mem(matrix, n-1, j,dp));
        // }
        // return ans;

        return opt(matrix);
    }
};

int main()
{
    return 0;
}