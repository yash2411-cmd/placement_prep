#include <bits/stdc++.h>
using namespace std;

//  time complexity is O(n) and space is also O(n)
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int left = 0;
        int ans = 0;
        int withk = 0;
        for (int right = 0; right < n; right++)
        {
            mp[nums[right]]++;
            if (mp.size() > k)
            {
                mp.erase(nums[left]);
                left++;
                withk = 0;
            }
            while (mp.size() == k && mp[nums[left]] > 1)
            {
                mp[nums[left]]--;
                left++;
                withk++;
            }
            if (mp.size() == k)
            {
                ans += withk + 1;
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}