#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // time complexity is O(n) and space is O(1)
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        int prd = 1;
        while (j < n)
        {
            prd *= nums[j];
            while (i <= j && prd >= k)
            {
                prd /= nums[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};
int main()
{
    return 0;
}