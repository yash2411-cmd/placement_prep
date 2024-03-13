#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time and space complexity of the code is O(n*m), the approach uses LCS,
    // we first fill the dp table for LCS and then traverse from the bottom right to up
    // to calculate the shortest common supersequence
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int ans = 0;
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";
        int i = n, j = m;

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }
        while (i > 0)
        {
            ans += str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans += str2[j - 1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    return 0;
}