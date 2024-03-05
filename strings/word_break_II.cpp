#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n * m * k) where n is len of string, m is length  of wordsDict and k is the avg len of word in wordDict and
    //   space complexity is O(n)
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto &word : wordDict)
            {
                // check for out of bounds
                if (i < word.length() - 1)
                {
                    continue;
                }

                // check if a substr of s exists in words
                if (i == word.length() - 1 || dp[i - word.length()])
                {
                    if (s.substr(i - word.length() + 1, word.length()) == word)
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};
int main()
{
    return 0;
}