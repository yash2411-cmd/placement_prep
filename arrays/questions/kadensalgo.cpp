#include <bits/stdc++.h>
using namespace std;
ios_base::sync_with_stdio(false);
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currsum = nums[0];
        int maxsum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currsum = max(currsum + nums[i], nums[i]);
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};

int main()
{
    return 0;
}