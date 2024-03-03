#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(int index, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &com)
    {
        if (target == 0)
        {
            ans.push_back(com);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }
            com.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], ans, com);
            com.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> com;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ans, com);
        return ans;
    }
};

int main()
{
    return 0;
}