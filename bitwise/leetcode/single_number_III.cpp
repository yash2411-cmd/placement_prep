#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xor_result = 0;
        for (auto i : nums)
        {
            xor_result ^= i;
        }
        unsigned int diff = xor_result & -static_cast<unsigned int>(xor_result); // used unsigned int to avoide integer overflow
        int a = 0, b = 0;
        for (auto num : nums)
        {
            if (num & diff)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }
        return {a, b};
    }
};

int main()
{
    return 0;
}