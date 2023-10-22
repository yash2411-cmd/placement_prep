#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int l, r;
        l = r = k;
        int ans = nums[k];
        int curr_min = nums[k];

        while (l > 0 || r < nums.size() - 1)
        {
            int left = l > 0 ? nums[l - 1] : 0;
            int right = r < nums.size() - 1 ? nums[r + 1] : 0;

            if (left > right)
            {
                l -= 1;
                curr_min = min(curr_min, left);
            }
            else
            {
                r += 1;
                curr_min = min(curr_min, right);
            }
            ans = max(ans, curr_min * (r - l + 1));
        }
        return ans;
    }
};

int main()
{
    return 0;
}