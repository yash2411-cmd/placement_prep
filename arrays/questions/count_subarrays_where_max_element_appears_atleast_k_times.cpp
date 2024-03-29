#include <bits/stdc++.h>
using namespace std;

// bf approach O(n^2)
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            long long cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == mx)
                {
                    cnt++;
                }
                if (cnt >= k)
                    ans++;
            }
        }
        return ans;
    }
};

// optimized approach O(n)
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0, count = 0;
        while (right < n)
        {
            if (nums[right] == mx)
            {
                count++;
                if (count >= k)
                {
                    ans += n - right;
                    while (nums[left] != mx)
                    {
                        left++;
                        ans += n - right;
                    }
                    left++;
                    count--;
                }
            }
            right++;
        }
        return ans;
    }
};
int main()
{
    return 0;
}