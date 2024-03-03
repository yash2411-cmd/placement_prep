#include <bits/stdc++.h>
using namespace std;
class Solution
{

    // the approach is using backtracking since we need the all unique possible combinations

public:
    void solve(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &combo, int currsum, int index)
    {
        // we backtrack
        if (currsum > target)
        {
            return;
        }
        // found one of the possible ans, store and return
        if (currsum == target)
        {
            ans.push_back(combo);
            return;
        }

        // traverse over the candidates array and calculate for every possible combination
        for (int i = index; i < candidates.size(); i++)
        {

            // storing the current element as it can be a possible contributor to the ans
            combo.push_back(candidates[i]);
            // update current sum
            currsum += candidates[i];
            // call the function for next posssible number
            solve(candidates, target, ans, combo, currsum, i);
            // back track to remove the privious combo from ans.
            combo.pop_back();
            currsum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> combo;

        solve(candidates, target, ans, combo, 0, 0);
        return ans;
    }
};

int main()
{
    return 0;
}