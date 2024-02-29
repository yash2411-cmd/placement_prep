#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
    {
        if (index == nums1.size())
        {
            return 0;
        }
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // main statement
        if (swapped)
        {
            // to handle the case where we are swapping the previous elements
            swap(prev1, prev2);
        }
        // no swapp case
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = solve(nums1, nums2, index + 1, 0);
        }
        // swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1));
        }
        return ans;
    }
    int mem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
    {
        if (index == nums1.size())
        {
            return 0;
        }
        int ans = INT_MAX;
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // main statement
        if (swapped)
        {
            // to handle the case where we are swapping the previous elements
            swap(prev1, prev2);
        }
        if (dp[index][swapped] != -1)
        {
            return dp[index][swapped];
        }
        // no swapp case
        if (nums1[index] > prev1 && nums2[index] > prev2)
        {
            ans = mem(nums1, nums2, index + 1, 0, dp);
        }
        // swap
        if (nums1[index] > prev2 && nums2[index] > prev1)
        {
            ans = min(ans, 1 + mem(nums1, nums2, index + 1, 1, dp));
        }
        return dp[index][swapped] = ans;
    }
    // time compx O(n) & space compx O(n)
    int tab(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // main statement
                if (swapped)
                {
                    // to handle the case where we are swapping the previous elements
                    swap(prev1, prev2);
                }
                // no swapp case
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = dp[index + 1][0];
                }
                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + dp[index + 1][1]);
                }
                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
    int opt(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int sp = 0;
        int noswap = 0;
        int currswap = 0;
        int currnoswap = 0;
        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // main statement
                if (swapped)
                {
                    // to handle the case where we are swapping the previous elements
                    swap(prev1, prev2);
                }
                // no swapp case
                if (nums1[index] > prev1 && nums2[index] > prev2)
                {
                    ans = noswap;
                }
                // swap
                if (nums1[index] > prev2 && nums2[index] > prev1)
                {
                    ans = min(ans, 1 + sp);
                }
                if (swapped)
                {
                    currswap = ans;
                }
                else
                {
                    currnoswap = ans;
                }
            }
            sp = currswap;
            noswap = currnoswap;
        }
        return min(sp, noswap);
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swapped = 0;
        // return solve(nums1, nums2, 1, swapped);
        // vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        // return mem(nums1, nums2, 1, swapped,dp);
        // return tab(nums1, nums2);
        return opt(nums1, nums2);
    }
};
int main()
{
    return 0;
}