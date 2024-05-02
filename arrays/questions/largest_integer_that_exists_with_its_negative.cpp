#include <bits/stdc++.h>
using namespace std;

class Solution
{
    //  time complexity of this is O(nlogn) and space is O(1);
public:
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] == 0)
                return nums[right];
            if (nums[left] + nums[right] < 0)
                left++;
            else
            {
                right--;
            }
        }
        return -1;
    }
};

int main()
{
    return 0;
}