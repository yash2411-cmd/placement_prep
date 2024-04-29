#include <bits/stdc++.h>
using namespace std;

// approch one
class Solution
{
public:
    string bin(int num)
    {
        bitset<sizeof(num) * 8> binary(num);
        return binary.to_string();
    }
    int minOperations(vector<int> &nums, int k)
    {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans ^= nums[i];
        }
        string a = bin(ans);
        string b = bin(k);
        int count = 0;
        for (int i = 0; i < 32; i++)
        { // Iterate over the bits of the binary representation
            if (a[i] != b[i])
            {
                count++;
            }
        }
        return count;
    }
};
// approach two
class Solution
{
public:
    // string bin(int num){
    //     bitset<sizeof(num) * 8> binary(num);
    //     return binary.to_string();
    // }
    int minOperations(vector<int> &nums, int k)
    {
        bitset<20> xorsum(0);
        for (auto num : nums)
        {
            xorsum ^= num;
        }
        bitset<20> k_bits(k);
        return (xorsum ^ k_bits).count();
    }
};

int main()
{
    return 0;
}