#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // time complexity is O(n) and space complexity is O(1)
    // we are using sliding window to solve this question

    // approach:  Subarrays exceeding the target sum are irrelevant to our objective. We only care about subarrays whose sum is either equal to the goal or less than the goal.

    // Leveraging this insight, we can modify the sliding window approach. Instead of directly shrinking the window when the currentSum reaches the goal, we can track the number of subarrays with a sum at most equal to the goal.
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

// this approach uses prefix sum time and space complexity for this approach is O(n)
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int sum = 0;
    int count = 0;
    map<int, int> freq;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == goal)
            count++;

        if (freq.find(sum - goal) != freq.end())
        {
            count += freq[sum - goal];
        }
        freq[sum]++;
    }
    return count;
}

int main()
{
    return 0;
}