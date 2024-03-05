#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // time and space complexity for both dp and backtracking solutions are O(n^2)
    bool pali(string s, int st, int e)
    {
        while (st < e)
        {
            if (s[st] != s[e])
            {
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>> &ans, vector<string> &output, int start)
    {
        if (start == s.size())
        {
            ans.push_back(output);
            return;
        }

        // check for all the possible ending indeces form the start
        for (int i = start; i < s.size(); i++)
        {
            if (pali(s, start, i))
            {
                output.push_back(s.substr(start, i - start + 1));
                solve(s, ans, output, i + 1);
                output.pop_back();
            }
        }
    }
    void mem(string s, vector<vector<string>> &ans, vector<string> &output, int start, unordered_map<int, vector<vector<string>>> &dp)
    {
        if (start == s.size())
        {
            ans.push_back(output);
            return;
        }
        if (dp.count(start))
        {
            for (auto part : dp[start])
            {
                vector<string> partition(output);
                partition.insert(partition.end(), part.begin(), part.end());
                ans.push_back(partition);
            }
        }

        // check for all the possible ending indeces form the start
        for (int i = start; i < s.size(); i++)
        {
            if (pali(s, start, i))
            {
                output.push_back(s.substr(start, i - start + 1));
                mem(s, ans, output, i + 1, dp);
                output.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<string>> ans;
        vector<string> output;
        // unordered_map<int, vector<vector<string>>> dp;
        solve(s, ans, output, 0);
        return ans;
    }
};

int main()
{
    return 0;
}