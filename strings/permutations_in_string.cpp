#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(string &s, set<string> &ans, int index)
    {
        if (index >= s.size())
        {
            ans.insert(s);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            swap(s[index], s[i]);
            solve(s, ans, index + 1);
            // swapping again to backtrack
            swap(s[index], s[i]);
        }
    }
    vector<string> find_permutation(string S)
    {
        // to handle duplicates we are using sets
        set<string> ans;
        solve(S, ans, 0);
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};

int main()
{
    return 0;
}