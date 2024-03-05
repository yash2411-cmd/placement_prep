#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n) and space is constant
    int longestSubarray(vector<int> &nums)
    {
        int ans = 0;
        int l = 0;
        int r = 0;
        bool iszero = false;
        int n = nums.size();
        while (r < n)
        {
            if (nums[r] == 0)
            {
                if (iszero)
                {
                    while (l < r)
                    {
                        if (nums[l++] == 0)
                        {
                            break;
                        }
                    }
                }
                iszero = true;
            }
            ans = max(ans, r - l);
            r++;
        }
        return max(ans, r - l - 1);
    }
};

class Solution
{
public:
    // time complexity is O(n) and space is also O(n)
    int longestSubarray(vector<int> &nums)
    {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] == 1)
            {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i + 1] == 1)
            {
                right[i] = right[i + 1] + 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};

int main()
{
    return 0;
}