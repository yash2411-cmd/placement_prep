#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int num : nums)
        {
            ans |= num;
        }
        return ans << (n - 1);
    }
};

int main()
{
    return 0;
}