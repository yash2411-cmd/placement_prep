#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //  time complexity of O(n) and space is constant
    int longestOnes(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ans = 0;
        int zerosCount = 0;
        while (right < n)
        {
            if (nums[right] == 0)
            {
                zerosCount++;
            }

            while (zerosCount > k)
            {
                if (nums[left] == 0)
                {
                    zerosCount--;
                }
                left++;
            }

            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}