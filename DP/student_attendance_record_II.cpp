#include <bits/stdc++.h>
using namespace std;

// memoiation solution time and space complexity is O(n)
class Solution
{
public:
    vector<vector<vector<int>>> dp;
    int mod = 1000000007;
    int solve(int n, int ab, int late)
    {
        if (ab >= 2 or late >= 3)
        {
            return 0;
        }
        if (n == 0)
            return 1;

        if (dp[n][ab][late] != -1)
        {
            return dp[n][ab][late];
        }

        int cnt = 0;
        // choosing p for current position
        cnt = solve(n - 1, ab, 0);
        // choosing a for current position
        cnt = (cnt + solve(n - 1, ab + 1, 0)) % mod;
        // choosing l for current position
        cnt = (cnt + solve(n - 1, ab, late + 1)) % mod;

        return dp[n][ab][late] = cnt;
    }
    int checkRecord(int n)
    {
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0);
    }
};

int main()
{
    return 0;
}