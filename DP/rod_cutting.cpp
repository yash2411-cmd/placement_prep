#include <bits/stdc++.h>
using namespace std;

// memoiation
int solve(int index, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return N * price[0];
    }
    if (dp[index][N] != -1)
    {
        return dp[index][N];
    }

    int nottake = solve(index - 1, N, price, dp);
    int take = INT_MIN;
    int rod = index + 1;
    if (rod <= N)
    {
        take = price[index] + solve(index, N - rod, price, dp);
    }
    return dp[index][N] = max(take, nottake);
}

int opt(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int nottake = prev[j];
            int take = INT_MIN;
            int rod = i + 1;
            if (rod <= j)
            {
                take = price[i] + curr[j - rod];
            }
            curr[j] = max(take, nottake);
        }
        prev = curr;
    }
    return prev[n];
}

int furtherOptimized(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        prev[i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int nottake = prev[j];
            int take = INT_MIN;
            int rod = i + 1;
            if (rod <= j)
            {
                take = price[i] + prev[j - rod];
            }
            prev[j] = max(take, nottake);
        }
    }
    return prev[n];
}
int cutRod(vector<int> &price, int n)
{ // tabulation
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int nottake = dp[i - 1][j];
            int take = INT_MIN;
            int rod = i + 1;
            if (rod <= j)
            {
                take = price[i] + dp[i][j - rod];
            }
            dp[i][j] = max(take, nottake);
        }
    }
    return dp[n - 1][n];
}

int main()
{
    return 0;
}