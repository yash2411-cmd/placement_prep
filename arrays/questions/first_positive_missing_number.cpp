#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();

        // Mark all the elements that are not in the range of the answer [1,n]
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = n + 1;
            }
        }

        // Mark elements that are present in the array
        for (int i = 0; i < n; i++)
        {
            int ele = abs(nums[i]);
            if (ele > n)
            {
                continue; // we know that this can't be our answer
            }
            ele--;
            if (nums[ele] > 0)
            {
                nums[ele] = -1 * nums[ele];
            }
        }

        // Find the first missing positive integer
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
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