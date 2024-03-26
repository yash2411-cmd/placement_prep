#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        vector<pair<int, int>> ans;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            int one = boxTypes[i][0];
            int two = boxTypes[i][1];
            ans.push_back({one, two});
        }
        sort(ans.begin(), ans.end(), [&](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });
        int res = 0;
        int cnt = 0; // Initialize cnt to 0
        for (auto i : ans)
        {
            while (i.first > 0 && cnt < truckSize)
            {                    // Check if there are boxes left and space in the truck
                res += i.second; // Add units
                i.first--;       // Decrease the count of boxes
                cnt++;           // Increment the count of boxes in the truck
            }
        }
        return res;
    }
};
int main()
{
    return 0;
}