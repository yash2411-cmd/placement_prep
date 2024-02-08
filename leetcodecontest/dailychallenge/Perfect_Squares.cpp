#include <bits/stdc++.h>
using namespace std;

static int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    return 0;
}();
class Solution
{
public:
    // first we generate all the perfect squares upto n
    vector<int> generatePerfectSquares(int n)
    {
        std::vector<int> perfectSquares;
        for (int i = 1; i * i <= n; ++i)
        {
            perfectSquares.push_back(i * i);
        }
        return perfectSquares;
    }

    // now we find minimum number of  perfect square numbers that can be arranged to make a sum equal to target
    int minPerfectSquares(int n, std::vector<int> &squares, std::vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int minCount = INT_MAX;
        for (int square : squares)
        {
            if (n - square >= 0)
            {
                minCount = std::min(minCount, minPerfectSquares(n - square, squares, dp) + 1);
            }
        }
        dp[n] = minCount;
        return minCount;
    }
    int numSquares(int n)
    {
        vector<int> perfect_sqaures = generatePerfectSquares(n);
        vector<int> dp(n + 1, -1);
        return minPerfectSquares(n, perfect_sqaures, dp);
    }
};

int main()
{
    return 0;
}