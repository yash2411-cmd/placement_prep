#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // time complexity is O(n) and space complexity is O(1)
    // we are using sliding window to solve this question
    int helper(vector<int> &nums, int goal)
    {
        int st = 0;
        int currsum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currsum += nums[i];

            while (st <= i && currsum > goal)
            {
                currsum -= nums[st++];
            }
            count += i - st + 1;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};

int main()
{
    return 0;
}