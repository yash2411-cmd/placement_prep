#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        // Convert the integer n to an array of digits
        vector<int> nums;
        while (n > 0)
        {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());

        // Find the first index i-1 where nums[i-1] < nums[i]
        int i = nums.size() - 1;
        while (i > 0 && nums[i - 1] >= nums[i])
        {
            i--;
        }

        // If no such index is found, return -1
        if (i == 0)
        {
            return -1;
        }

        // Find the smallest digit to the right of nums[i-1] but greater than nums[i-1]
        int j = nums.size() - 1;
        while (nums[j] <= nums[i - 1])
        {
            j--;
        }

        // Swap nums[i-1] with the found digit
        swap(nums[i - 1], nums[j]);

        // Reverse the subarray to the right of nums[i-1]
        reverse(nums.begin() + i, nums.end());

        // Convert the modified array of digits back to an integer
        long long result = 0;
        for (int digit : nums)
        {
            result = result * 10 + digit;
            // Check for 32-bit integer limit
            if (result > INT_MAX)
            {
                return -1;
            }
        }

        return int(result);
    }
};

int main()
{
    return 0;
}