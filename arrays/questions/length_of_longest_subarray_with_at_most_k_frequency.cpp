#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // sliding window pattern
    // time complexity is O(n) and space is O(n)
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < n)
        {
            int right = nums[r++];
            mp[right]++;
            while (mp[right] > k)
            {
                int left = nums[l++];
                mp[left]--;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};

int main()
{
    return 0;
}