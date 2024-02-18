#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tabulation(int n)
    {
        vector<int> dp(38, -1);
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }

    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 1;

        for (int i = 0; i < n - 2; i++)
        {
            int temp = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = temp;
        }
        return prev3;
    }
};

int main()
{
    return 0;
}