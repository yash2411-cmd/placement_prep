#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n^2) and space complexity is O(n)
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int maxlen = 1;
        vector<int> lengths(n, 1);
        vector<int> count(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (lengths[j] + 1 > lengths[i])
                    {
                        lengths[i] = lengths[j] + 1;
                        count[i] = count[j];
                    }
                    else if (lengths[j] + 1 == lengths[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            maxlen = max(maxlen, lengths[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (lengths[i] == maxlen)
                ans += count[i];
        }
        return ans;
    }
};
int main()
{
    return 0;
}