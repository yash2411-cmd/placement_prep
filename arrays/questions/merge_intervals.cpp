#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        ios_base::sync_with_stdio(false);
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        // if(intervals.size()==0)return ans;
        vector<int> temp = intervals[0];
        for (auto i : intervals)
        {
            if (i[0] <= temp[1])
            {
                temp[1] = max(temp[1], i[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = i;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

int main()
{
    return 0;
}