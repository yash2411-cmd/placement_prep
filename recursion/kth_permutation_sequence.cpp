#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        int fact = 1;
        // first we store integers from 1 to n in out array and calculate the factorial upto n-1
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k - 1;
        string ans = "";
        while (true)
        {
            // pushing the first number of our permutation
            ans += to_string(nums[k / fact]);
            // erasing that number from nums array
            nums.erase(nums.begin() + k / fact);
            if (nums.size() == 0)
            {
                break;
            }
            k = k % fact;
            fact = fact / nums.size();
        }
        return ans;
    }
};

int main()
{
    return 0;
}