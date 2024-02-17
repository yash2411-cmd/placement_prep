#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // optimized approach using two pointers and making ans in auxilary space
    vector<int> rearrangeArray(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans(nums.size(), 0);
        int pos = 0, neg = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                ans[pos] = nums[i];
                pos += 2;
            }
            else
            {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};

int main()
{
    return 0;
}