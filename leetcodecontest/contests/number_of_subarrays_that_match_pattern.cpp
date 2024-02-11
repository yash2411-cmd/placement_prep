#include <bits/stdc++.h>
using namespace std;

// You are given a 0-indexed integer array nums of size n, and a 0-indexed integer array pattern of size m consisting of integers -1, 0, and 1.

// A subarray nums[i..j] of size m + 1 is said to match the pattern if the following conditions hold for each element pattern[k]:

// nums[i + k + 1] > nums[i + k] if pattern[k] == 1.
// nums[i + k + 1] == nums[i + k] if pattern[k] == 0.
// nums[i + k + 1] < nums[i + k] if pattern[k] == -1.
// Return the count of subarrays in nums that match the pattern.

class Solution
{
public:
    int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
    {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        for (int i = 0; i <= n - m; i++)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (pattern[j] == 1 && (i + j + 1 >= n || nums[i + j + 1] <= nums[i + j]))
                {
                    match = false;
                    break;
                }
                else if (pattern[j] == 0 && (i + j + 1 >= n || nums[i + j + 1] != nums[i + j]))
                {
                    match = false;
                    break;
                }
                else if (pattern[j] == -1 && (i + j + 1 >= n || nums[i + j + 1] >= nums[i + j]))
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}