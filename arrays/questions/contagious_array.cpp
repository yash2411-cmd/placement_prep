#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            count += (nums[i] == 1 ? 1 : -1);
            if (mp.find(count) != mp.end())
            {
                ans = max(ans, i - mp[count]);
            }
            else
            {
                mp[count] = i;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}