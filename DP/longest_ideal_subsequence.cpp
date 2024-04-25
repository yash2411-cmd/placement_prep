#include <bits/stdc++.h>
using namespace std;

// both the approaches have a time complexity of O(n) and space of O(n*26)
class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int ans = 0;
        int n = s.size();
        vector<int> dp(n, 1);
        int last[26] = {0};
        for (int i = 0; i < n; i++)
        {
            int ch = s[i] - 'a';
            for (int j = max(0, ch - k); j <= min(25, ch + k); j++)
            {
                dp[i] = max(dp[i], last[j] + 1);
            }
            last[ch] = max(last[ch], dp[i]);
            ans = max(ans, last[ch]);
        }
        // ans = *max_element(dp.begin(), dp.end());
        return ans;
    }
};

class Solution
{
public:
    int solve(string &s, int k, int index, int lastchar, vector<vector<int>> &dp)
    {
        if (index == s.size())
            return 0;
        if (dp[index][lastchar] != -1)
        {
            return dp[index][lastchar];
        }
        int ans = solve(s, k, index + 1, lastchar, dp);
        if (lastchar == 26 || abs((s[index] - 'a') - lastchar) <= k)
        {
            ans = max(ans, 1 + solve(s, k, index + 1, s[index] - 'a', dp));
        }
        return dp[index][lastchar] = ans;
    }
    int longestIdealString(string s, int k)
    {
        vector<vector<int>> dp(s.size(), vector<int>(27, -1));
        return solve(s, k, 0, 26, dp);
    }
};

int main()
{
    return 0;
}