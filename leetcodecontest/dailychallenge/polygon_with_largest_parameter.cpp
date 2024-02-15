#include <bits/stdc++.h>
using namespace std;

// Algorithm
// Sort the input array nums in ascending order.
// Initialize variables previous_elements_sum to 0 and ans to -1.
// Iterate through each element num in the sorted array nums.
// Check if the current element num is less than the sum of previous elements. If true, we have encountered a valid combination of sides.
// If the current num is a valid side, update ans to the sum of the current num and previous_elements_sum.
// Update previous_elements_sum by adding the current element num.
// After iterating through all elements, the method returns the largest possible perimeter stored in ans.

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        ios::sync_with_stdio(false);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long prev_sum = 0;
        long long ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < prev_sum)
            {
                ans = nums[i] + prev_sum;
            }
            prev_sum += nums[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}