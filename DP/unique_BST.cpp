#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // one word solution to this problem is catalan number

    int mem(int n, vector<int> &dp)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += mem(i - 1, dp) * mem(n - i, dp);
        }
        return dp[n] = ans;
    }
    int tab(int n)
    {
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        // i -> numvber or nodes
        for (int i = 2; i <= n; i++)
        {
            // j  root node
            for (int j = 1; j < i + 1; j++)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return mem(n, dp);
    }
};
int main()
{
    return 0;
}