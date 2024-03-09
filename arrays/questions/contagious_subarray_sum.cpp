#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_set<int> prefix(nums.size());
        if (nums.size() < 2)
        {
            return false;
        }

        int sum = 0;
        int rem = 0;
        int prevmod = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            rem = (k == 0) ? sum : sum % k;
            if (prefix.find(rem) != prefix.end())
            {
                return true;
            }
            prefix.insert(prevmod);
            prevmod = rem;
        }
        return false;
    }
};

int main()
{
    return 0;
}