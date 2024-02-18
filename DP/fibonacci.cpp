#include <bits/stdc++.h>
using namespace std;

// memoization
int fun(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fun(n - 1, dp) + fun(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;

    // vector<int> dp(n + 1, -1);
    // cout << fun(n, dp) << endl;

    // tabulation
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // cout << dp[n] << endl;

    // space optimization

    int prev1 = 1;
    int prev2 = 0;
    if (n == 0)
    {
        cout << prev2 << endl;
    }
    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1 << endl;

    return 0;
}