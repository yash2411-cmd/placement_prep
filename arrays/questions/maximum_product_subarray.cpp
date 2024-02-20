#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int l_left = INT_MIN;
        int l_right = INT_MIN;
        int r = 1;
        int l = 1;
        for (int i = 0; i < n; i++)
        {
            l *= nums[i];
            r *= nums[n - i - 1];

            l_left = max(l_left, l);
            l_right = max(l_right, r);
            if (nums[n - i - 1] == 0)
            {
                r = 1;
            }
            if (nums[i] == 0)
            {
                l = 1;
            }
        }
        return max(l_right, l_left);
    }
};

int main()
{
    return 0;
}