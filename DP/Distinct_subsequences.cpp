#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &str, string &output, int i, string &t)
    {
        if (i >= str.length())
        {
            if (output == t)
            { // Check if output is a subsequence of t
                return 1;
            }
            return 0;
        }

        int not_take = solve(str, output, i + 1, t);
        output.push_back(str[i]);
        int take = solve(str, output, i + 1, t);
        output.pop_back(); // Backtrack to remove the last character

        return not_take + take;
    }

    // time complexity is O(nxm) and space is also same
    int mem(string &str, int i, string &t, int j, vector<vector<int>> &dp)
    {
        if (j >= t.length())
        {
            return 1; // Subsequence found
        }
        if (i >= str.length())
        {
            return 0; // Reached end of s, but subsequence not found
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int not_take = mem(str, i + 1, t, j, dp);
        int take = (str[i] == t[j]) ? mem(str, i + 1, t, j + 1, dp) : 0;

        return dp[i][j] = not_take + take;
    }
    int numDistinct(string s, string t)
    {
        // string output;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return mem(s, 0, t, 0, dp);
    }
};

int main()
{
    return 0;
}