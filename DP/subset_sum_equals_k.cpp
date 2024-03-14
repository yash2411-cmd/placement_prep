#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

bool solve(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (index == 0)
    {
        return (target == arr[0]);
    }
    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }
    bool include = false;
    if (arr[index] <= target)
    {
        include = solve(index - 1, arr, target - arr[index], dp);
    }
    bool ex = solve(index - 1, arr, target, dp);
    return dp[index][target] = include or ex;
}

bool tab(vector<int> &arr, int k, int n)
{
    vector<bool> prev(k + 1, 0);
    vector<bool> curr(k + 1, 0);
    prev[0] = true;
    prev[arr[0]] = true;
    curr[0] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool include = false;
            if (arr[i] <= target)
            {
                include = prev[target - arr[i]];
            }
            bool ex = prev[target];
            curr[target] = include or ex;
        }
        prev = curr;
    }
    return prev[k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return tab(arr, k, n);
}

int main()
{
    return 0;
}