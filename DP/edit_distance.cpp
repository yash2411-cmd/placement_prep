#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        // if firsts string is smaller than second then we can acheive string b
        // by inserting the rest of the characters of b in a so that will be ans
        if (i == a.length())
        {
            return b.length() - j;
        }
        if (j == b.length())
        {
            return a.length() - i;
        }

        int ans = 0;
        if (a[i] == b[j])
        {
            return solve(a, b, i + 1, j + 1);
        }
        else
        {
            // insert
            int insertans = 1 + solve(a, b, i, j + 1);
            // delete
            int deleteans = 1 + solve(a, b, i + 1, j);
            // replace
            int replaceans = 1 + solve(a, b, i + 1, j + 1);

            ans = min(insertans, min(deleteans, replaceans));
        }
        return ans;
    }
    int mem(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        // if firsts string is smaller than second then we can acheive string b
        // by inserting the rest of the characters of b in a so that will be ans
        if (i == a.length())
        {
            return b.length() - j;
        }
        if (j == b.length())
        {
            return a.length() - i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j])
        {
            return mem(a, b, i + 1, j + 1, dp);
        }
        else
        {
            // insert
            int insertans = 1 + mem(a, b, i, j + 1, dp);
            // delete
            int deleteans = 1 + mem(a, b, i + 1, j, dp);
            // replace
            int replaceans = 1 + mem(a, b, i + 1, j + 1, dp);

            ans = min(insertans, min(deleteans, replaceans));
        }
        return dp[i][j] = ans;
    }
    int tab(string a, string b)
    {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        // handling base cases
        for (int j = 0; j < b.length(); j++)
        {
            dp[a.length()][j] = b.length() - j;
        }
        for (int i = 0; i < a.length(); i++)
        {
            dp[i][b.length()] = a.length() - i;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = dp[i + 1][j + 1];
                }
                else
                {
                    // insert
                    int insertans = 1 + dp[i][j + 1];
                    // delete
                    int deleteans = 1 + dp[i + 1][j];
                    // replace
                    int replaceans = 1 + dp[i + 1][j + 1];

                    ans = min(insertans, min(deleteans, replaceans));
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }
    int opt(string a, string b)
    {

        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);
        // handling base cases
        for (int j = 0; j < b.length(); j++)
        {
            next[j] = b.length() - j;
        }
        // for(int i =0;i<a.length();i++){
        //     dp[i][b.length()] = a.length() - i;
        // }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                curr[b.length()] = a.length() - i;
                // updating second base case here most important

                int ans = 0;
                if (a[i] == b[j])
                {
                    ans = next[j + 1];
                }
                else
                {
                    // insert
                    int insertans = 1 + curr[j + 1];
                    // delete
                    int deleteans = 1 + next[j];
                    // replace
                    int replaceans = 1 + next[j + 1];

                    ans = min(insertans, min(deleteans, replaceans));
                }
                curr[j] = ans;
            }
            next = curr;
        }

        return next[0];
    }

    int minDistance(string word1, string word2)
    {
        // return solve(word1, word2, 0, 0);
        // vector<vector<int>> dp(word1.length()+1, vector<int> (word2.length()+1, -1));
        //  return mem(word1, word2, 0, 0,dp);
        if (word1.length() == 0)
        {
            return word2.length();
        }
        if (word2.length() == 0)
        {
            return word1.length();
        }
        return opt(word1, word2);
    }
};

int main()

{
    return 0;
}