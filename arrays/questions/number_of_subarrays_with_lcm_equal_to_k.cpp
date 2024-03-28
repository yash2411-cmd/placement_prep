#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int gcd(long long a, int b) { return b == 0 ? a : gcd(b, a % b); }

    // int lcm(long long a, int b) { return (a * b) / gcd(a, b); }
    int subarrayLCM(vector<int> &nums, int k)
    {
        long long ans = 0;
        // int j = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            long long curr_lcm = nums[i];
            // if(curr_lcm == k)ans++;
            for (int j = i; j < n; j++)
            {
                curr_lcm = lcm(curr_lcm, nums[j]);
                if (curr_lcm > k)
                    break;
                if (curr_lcm == k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}