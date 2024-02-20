#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weights, vector<int> &values, int index, int capacity)
{
    if (index == 0)
    {
        if (weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + solve(weights, values, index - 1, capacity - weights[index]);
    }
    int exclude = solve(weights, values, index - 1, capacity);
    return max(include, exclude);
}
int mem(vector<int> &weights, vector<int> &values, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weights[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weights[index] <= capacity)
    {
        include = values[index] + mem(weights, values, index - 1, capacity - weights[index], dp);
    }
    int exclude = mem(weights, values, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int tab(vector<int> &weights, vector<int> &values, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));

    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
        {
            dp[0][w] = values[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int include = 0;
            if (weights[index] <= j)
            {
                include = values[index] + dp[index - 1][j - weights[index]];
            }
            int exclude = dp[index - 1][j];

            dp[index][j] = max(include, exclude);
        }
    }
    return dp[n - 1][capacity];
}

int optimized(vector<int> &weights, vector<int> &values, int n, int capacity)
{

    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weights[0]; w <= capacity; w++)
    {
        if (weights[0] <= capacity)
        {
            prev[w] = values[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            int include = 0;
            if (weights[index] <= j)
            {
                include = values[index] + prev[j - weights[index]];
            }
            int exclude = prev[j];

            curr[j] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // return solve(weights, values, n-1, w);
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return mem(weights, values, n - 1, w, dp);

    return optimized(weights, values, n, w);
}

int main()
{
    return 0;
}