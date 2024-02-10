#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // all the single characters are already a palindrome
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            count++;
        }
        // checking for palindrome of length 2
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                count++;
            }
        }
        // check for palindrome with length greater than 2
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i < n - len + 1; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    count++;
                }
            }
        }
        return count;
    }
};

// second way using iterative way
class Solution
{
public:
    int solve(string s, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s)
    {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int j = i;
            int odd = solve(s, i, j);
            int even = solve(s, i, j + 1);

            count += odd + even;
        }
        return count;
    }
};

int main()
{
    return 0;
}