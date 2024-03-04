#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int open, int close, vector<string> &ans, string s)
    {

        if (open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            solve(open - 1, close, ans, s);
            // backtracking
            s.pop_back();
        }
        if (close > open)
        {
            s.push_back(')');
            solve(open, close - 1, ans, s);
            // backtracking
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int o = n;
        int c = n;
        vector<string> ans;
        solve(o, c, ans, "");
        return ans;
    }
};

int main()
{
    return 0;
}