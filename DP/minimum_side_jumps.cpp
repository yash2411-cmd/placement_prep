#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &ob, int lane, int pos)
    {
        int n = ob.size() - 1;
        if (pos == n)
        {
            return 0;
        }
        if (ob[pos + 1] != lane)
        {
            return solve(ob, lane, pos + 1);
        }
        else
        {
            // only three choices for jumps
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (lane != i && ob[pos] != i)
                {
                    ans = min(ans, 1 + solve(ob, i, pos));
                }
            }
            return ans;
        }
    }
    int mem(vector<int> &ob, int lane, int pos, vector<vector<int>> &dp)
    {
        int n = ob.size() - 1;
        if (pos == n)
        {
            return 0;
        }
        if (ob[pos + 1] != lane)
        {
            return mem(ob, lane, pos + 1, dp);
        }
        if (dp[lane][pos] != -1)
        {
            return dp[lane][pos];
        }
        else
        {
            // only three choices for jumps
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                if (lane != i && ob[pos] != i)
                {
                    ans = min(ans, 1 + mem(ob, i, pos, dp));
                }
            }
            dp[lane][pos] = ans;
            return dp[lane][pos];
        }
    }
    // TC O(3*n) SC O(4*N)
    int tab(vector<int> &ob)
    {
        int n = ob.size() - 1;
        vector<vector<int>> dp(4, vector<int>(ob.size(), 1e9));
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (ob[pos + 1] != lane)
                {
                    dp[lane][pos] = dp[lane][pos + 1];
                }
                else
                {
                    // only three choices for jumps
                    int ans = INT_MAX;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (lane != i && ob[pos] != i)
                        {
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }
                    dp[lane][pos] = ans;
                }
            }
        }
        return min(dp[2][0], min(dp[1][0] + 1, dp[3][0] + 1));
    }
    // TC O(N) SC O(1)
    int optimized(vector<int> &ob)
    {
        int n = ob.size() - 1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int pos = n - 1; pos >= 0; pos--)
        {
            for (int lane = 1; lane <= 3; lane++)
            {
                if (ob[pos + 1] != lane)
                {
                    curr[lane] = next[lane];
                }
                else
                {
                    // only three choices for jumps
                    int ans = INT_MAX;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (lane != i && ob[pos] != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(next[1] + 1, next[3] + 1));
    }

    int minSideJumps(vector<int> &obstacles)
    {
        // return solve(obstacles, 2, 0);
        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return mem(obstacles, 2, 0, dp);
        // return tab(obstacles);
        return optimized(obstacles);
    }
};
int main()
{
    return 0;
}