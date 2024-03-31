#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int> &nums)
    {
        long long ans = 1;
        //         int start = 0;

        //         for (int end = 0; end < nums.size(); end++) {
        //             if (end > 0 && nums[end] == nums[end - 1]) {
        //                 start = end - 1;
        //             }
        //             ans += end - start + 1;
        //         }

        //         return ans;
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            ans += dp[i];
        }
        return ans;
    }
};

int main()
{
    return 0;
}