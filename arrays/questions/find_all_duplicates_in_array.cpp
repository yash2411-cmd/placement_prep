#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // here we use switch methods  to solve the problem, as it is a basic
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0)
            {
                ans.push_back(index + 1);
            }
            else
            {
                nums[index] = -nums[index];
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}