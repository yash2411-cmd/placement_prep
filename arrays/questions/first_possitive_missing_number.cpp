#include <bits/stdc++.h>
using namespace std;
// time complexity is O(nlogn) and space is O(n)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 1;
        set<int> second;
        for (auto i : nums)
        {
            if (i > 0)
            {
                second.insert(i);
            }
        }
        for (auto i : second)
        {
            if (i > ans)
            {
                return ans;
            }
            ans++;
        }
        return ans;
    }
};

class Solution
{
public:
    // uses cyclic sort  algorithm to sort the array in O(n) and auxiliary space of O(1)
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        while (i < n)
        {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
            else
            {
                i++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

int main()
{
    return 0;
}