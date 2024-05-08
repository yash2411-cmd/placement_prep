#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n) and space complexity if also O(n)
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> cp(score.begin(), score.end());
        sort(score.begin(), score.end(), greater<int>());
        unordered_map<int, int> mp;
        for (int i = 0; i < score.size(); i++)
        {
            mp[score[i]] = i + 1;
        }
        // 10 9 8 4 3
        // 1  2 3 4 5
        vector<string> ans(score.size());
        for (int i = 0; i < cp.size(); i++)
        {
            if (mp[cp[i]] == 1)
            {
                ans[i] = "Gold Medal";
            }
            else if (mp[cp[i]] == 2)
            {
                ans[i] = "Silver Medal";
            }
            else if (mp[cp[i]] == 3)
            {
                ans[i] = "Bronze Medal";
            }
            else
            {
                ans[i] = to_string(mp[cp[i]]);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}