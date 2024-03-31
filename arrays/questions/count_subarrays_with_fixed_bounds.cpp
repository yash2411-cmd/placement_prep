#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // used sliding window approach time O(n) and space is constant
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        int mn = -1, mx = -1;
        int st = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // check if the current element is out of range then reset the min and max to -1
            if (nums[i] < minK || nums[i] > maxK)
            {
                st = i + 1; // move to the next index
                mx = mn = -1;
            }
            else
            {
                // update the min and max
                if (nums[i] == minK)
                {
                    mn = i;
                }
                if (nums[i] == maxK)
                {
                    mx = i;
                }
                // finding the max number of subarrays in the given window
                ans += max(0, min(mn, mx) - st + 1);
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}