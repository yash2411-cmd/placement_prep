#include <bits/stdc++.h>
using namespace std;

// this question comes under dp and greedy can be solved by both but fast and clean code is with greedy
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int l = 0;
        int r = 0;
        int count = 0;
        int far = 0;
        while (r < nums.size() - 1)
        {
            for (int i = l; i <= r; i++)
            {
                far = max(far, i + nums[i]);
            }
            l = r + 1;
            r = far;
            count++;
        }
        return count;
    }
};

int main()
{
    return 0;
}