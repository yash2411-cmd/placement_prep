#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        int count = 0;

        for (int num : nums)
        {
            int complement = k - num;
            if (freq[complement] > 0)
            {
                count++;
                freq[complement]--;
            }
            else
            {
                freq[num]++;
            }
        }

        return count;
    }
};

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] == k)
            {
                i++;
                j--;
                count++;
            }
            else if (nums[i] + nums[j] > k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return count;
    }
};

int main()
{
    return 0;
}