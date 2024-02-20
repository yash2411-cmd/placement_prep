#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int solve(int n, vector<long long int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = (((n - 1) % mod) * (((solve(n - 1, dp)) % mod + (solve(n - 2, dp)) % mod) % mod)) % mod;
    return dp[n];
}

long long int tab(int n)
{
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % mod;
        long long int second = dp[i - 2] % mod;
        long long int ans = (((i - 1) % mod) * (first + second) % mod) % mod;
        dp[i] = ans;
    }
    return dp[n];
}

long long int optimized(int n)
{

    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % mod;
        long long int second = prev2 % mod;
        long long int ans = (((i - 1) % mod) * (first + second) % mod) % mod;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}
long long int countDerangements(int n)
{
    // vector<long long int> dp(n + 1, -1);
    // return solve(n, dp);
    // return tab(n);
    return optimized(n);
}
