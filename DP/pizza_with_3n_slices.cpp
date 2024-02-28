#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int end, vector<int> &slices, int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (index > end)
        {
            return 0;
        }
        int take = slices[index] + solve(index + 2, end, slices, n - 1);
        int not_take = solve(index + 1, end, slices, n);
        return max(take, not_take);
    }
    int mem(int index, int end, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || index > end)
        {
            return 0;
        }
        if (dp[index][n] != -1)
        {
            return dp[index][n];
        }
        int take = slices[index] + mem(index + 2, end, slices, n - 1, dp);
        int not_take = mem(index + 1, end, slices, n, dp);
        dp[index][n] = max(take, not_take);
        return dp[index][n];
    }
    int tab(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k, 0));

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp1[index + 2][n - 1];
                int not_take = dp1[index + 1][n];
                dp1[index][n] = max(take, not_take);
            }
        }
        int case1 = dp1[0][k / 3];
        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + dp2[index + 2][n - 1];
                int not_take = dp2[index + 1][n];
                dp2[index][n] = max(take, not_take);
            }
        }
        int case2 = dp2[1][k / 3];
        return max(case1, case2);
    }
    // time complexity is O(k^2) and space complexity is O(k)
    int opt(vector<int> &slices)
    {
        int k = slices.size();
        vector<int> prev1(k + 2, 0);
        vector<int> curr1(k + 2, 0);
        vector<int> next1(k + 2, 0);

        vector<int> prev2(k + 2, 0);
        vector<int> curr2(k + 2, 0);
        vector<int> next2(k + 2, 0);

        for (int index = k - 2; index >= 0; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + next1[n - 1];
                int not_take = curr1[n];
                prev1[n] = max(take, not_take);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k / 3];
        for (int index = k - 1; index >= 1; index--)
        {
            for (int n = 1; n <= k / 3; n++)
            {
                int take = slices[index] + next2[n - 1];
                int not_take = curr2[n];
                prev2[n] = max(take, not_take);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k / 3];
        return max(case1, case2);
    }

    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        // int case1 = solve(0,k-2, slices, k/3);
        // int case2 = solve(1, k-1,slices, k/3);
        // return max(case1, case2);
        return opt(slices);
    }
};

int main()
{
    return 0;
}