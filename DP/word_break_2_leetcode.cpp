#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // there is one more solution which is more optimized using trie approach with the same time and space complexites.
    // time and space complexity of this solution is O(2^n)
    bool isvalid(string &word, vector<string> &wordDict)
    {
        for (auto wrd : wordDict)
        {
            if (wrd == word)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<int, vector<string>> dp;
        // traversing from back of the original string
        for (int i = s.size(); i >= 0; i--)
        {
            vector<string> sentence; // to store a valid sentance

            for (int j = i; j < s.size(); j++)
            {
                // current word in the string
                string curr = s.substr(i, j - i + 1);

                // check if word is in the wordDict
                if (isvalid(curr, wordDict))
                {
                    // if its a last word
                    if (j == s.size() - 1)
                    {
                        sentence.push_back(curr);
                    }
                    else
                    {
                        vector<string> nextindex = dp[j + 1];
                        for (auto sent : nextindex)
                        {
                            sentence.push_back(curr + " " + sent);
                        }
                    }
                }
            }
            dp[i] = sentence;
        }
        return dp[0];
    }
};

int main()
{
    return 0;
}