#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int curr = right;
        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                ans[curr] = pow(nums[left], 2);
                left++;
            }
            else
            {
                ans[curr] = pow(nums[right], 2);
                right--;
            }
            curr--;
        }
        return ans;
    }
};
int main()
{
    return 0;
}