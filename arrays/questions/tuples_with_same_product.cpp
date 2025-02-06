#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                mp[(nums[i] * nums[j])]++;
            }
        }

        for (auto i : mp)
        {
            if (i.second > 1)
            {
                ans += (i.second * (i.second - 1) / 2) * 8;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {2, 3, 4, 6};
    cout << s.tupleSameProduct(v) << endl;
    return 0;
}