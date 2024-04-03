#include <bits/stdc++.h>
using namespace std;

// brute force approach to check for each substring O(n^2)
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.length();
        for (int len = 1; len <= n / 2; len++)
        {
            if (n % len == 0)
            {
                string pattern = s.substr(0, len);
                bool repeated = true;
                for (int i = len; i < n; i += len)
                {
                    if (s.substr(i, len) != pattern)
                    {
                        repeated = false;
                        break;
                    }
                }
                if (repeated)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}