#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> ans;
        unordered_set<int> winners;
        unordered_map<int, int> loosers;
        for (int i = 0; i < matches.size(); i++)
        {
            int win = matches[i][0];
            int lose = matches[i][1];
            winners.insert(win);
            loosers[lose]++;
            ;
        }
        vector<int> win;
        for (auto i : winners)
        {
            if (loosers.find(i) == loosers.end())
            {
                win.push_back(i);
            }
        }
        sort(win.begin(), win.end());
        ans.push_back(win);
        vector<int> loss;
        for (auto i : loosers)
        {
            if (i.second == 1)
            {
                loss.push_back(i.first);
            }
        }
        sort(loss.begin(), loss.end());
        ans.push_back(loss);
        return ans;
    }
};

int main()
{
    return 0;
}